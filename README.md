# 项目介绍
- 项目介绍：这是一个基于ROS2的智能小车项目，用于在gazebo仿真环境中实现智能小车的导航和巡逻功能。

# 以下时项目具体开发流程
# 一、创建小车模型
## 1. 创建工作环境
### 1.1 创建一个workspace, 并在该工作空间中创建一个包
- 之后机器人的建模和仿真环境的开发都在这个包下（my_robot_description）
### 1.2 创建urdf包来存储机器人的模型（采用分模块开发.xacro文件格式）
- 创建/urdf/main.urdf.xacro文件，用于引用其他文件的宏，汇总文件
- 创建/urdf/sensor/.urdf.xacro文件用于开发小车的感知模块（摄像头，雷达等等）
- 创建/urdf/actuator/.urdf.xacro文件用于开发小车执行模块（轮子，方向决策等等）
- 创建/urdf/base.urdf.xacro文件用于开发小车的主身体模块
- 创建/urdf/inertia.xacro文件用于开发小车的物理性质模块（碰撞、惯性等等）
### 1.3 创建world文件夹来存储仿真环境
- 创建/world/.sdf文件，用于加载gazebo仿真环境
### 1.4 创建launch文件包来存储脚本文件
- 创建/launch/.launch.py的脚本文件用于启动多个节点，不用一个一个麻烦的输入命令行
- 脚本用于启动Rviz和加载机器人模型到Rviz当中
### 1.5 机器人物理性质实现
- 将inertia.xacro中的宏引用到各个.urdf.xacro文件当中实现小车的物理性质
- 实现惯性，质量等物理性质。各个部件引用。


## 2. 将机器人加载到gazebo仿真环境中
### 2.1 创建gazebo_sim,launch.py的文件
- 该脚本要实现 加载launch文件路径，小车urdf文件路径，world文件路径到gazrbo sim中
- 需要实现将小车的.urdf文件转换为.sdf格式来让gazobo可以识别显示
- 代码
- ```
import launch
import launch_ros
from ament_index_python.packages import get_package_share_directory
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
import subprocess
import tempfile

def generate_launch_description():
    # 获取包的共享目录路径
    robot_name_in_model = 'carbot'
    urdf_tutorial_path = get_package_share_directory('my_arm_description')

    # xacro 文件路径
    default_model_path = urdf_tutorial_path + '/urdf/' + robot_name_in_model + '.urdf.xacro'

    # world 文件路径
    default_world_path = urdf_tutorial_path + '/world/custom_room.sdf'

    # 为launch声明参数
    action_declare_arg_model_path = launch.actions.DeclareLaunchArgument(
        name='model',
        default_value=default_model_path,
        description='XACRO model file path'
    )

    # 获取文件内容生成新的参数
    robot_description =launch_ros.parameters_description.ParameterValue(
        launch.substitutions.Command(
            ['xacro', launch.substitutions.LaunchConfiguration('model')]),
        value_type=str)

    # 通过 IncludeLaunchDescription 包含另外一个 launch 文件
    launch_gazebo = launch.actions.IncludeLaunchDescription(
        PythonLaunchDescriptionSource([get_package_share_directory(
            'gazebo_ros'), '/launch', '/gazebo.launch.py']),
        # 传递参数
        launch_arguments=[('world', default_world_path),('verbose','true')]
    )

    # 请求 Gazebo 加载机器人
    spawn_entity_node = launch_ros.actions.Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=['-topic', '/robot_description',
                   '-entity', robot_name_in_model, ])

	# 启动时 按顺序运行以下脚本
    return launch.LaunchDescription([
        action_declare_arg_mode_path,
        robot_state_publisher_node,
        launch_gazebo,
        spawn_entity_node,
    ])
  ```
### 2.2 URDF中扩展Gazebo标签
- 通过添加标签`<gazebo>  </gazebo>`来实现小车在仿真环境中的颜色，物理性质等因素的实现
### 2.3 使用两轮差速插件控制机器人
- 创建插件包urdf/carbot/plugins，包下创建两轮差速的插件（libgazebo_ros_diff_drive.so）这个动态库
- 该库 订阅ros2的/cmd_vel话题，并发布机器人的里程计位置信息到/odom和/tf两个话题中
- 之后在carbot.urdf.xacro中调用插件的宏
- 关键代码
```
<?xml version="1.0"?>
<robot xmlns:xacro="http://www.ros.org/wiki/xacro">
    <xacro:macro name="gazebo_control_plugin">
        <gazebo>
            <plugin name='diff_drive' filename='libgazebo_ros_diff_drive.so'>
            
                <ros>
                    <namespace>/</namespace>
                    <remapping>cmd_vel:=cmd_vel</remapping>
                    <remapping>odom:=odom</remapping>
                </ros>

                <update_rate>30</update_rate>
                <!-- wheels -->
                <left_joint>left_wheel_joint</left_joint>
                <right_joint>right_wheel_joint</right_joint>

                <!-- kinematics -->
                <wheel_separation>0.2</wheel_separation>
                <wheel_diameter>0.064</wheel_diameter>

                <!-- limits -->
                <max_wheel_torque>20</max_wheel_torque>
                <max_wheel_acceleration>1.0</max_wheel_acceleration>

                <!-- output -->
                <publish_odom>true</publish_odom>
                <publish_odom_tf>true</publish_odom_tf>
                <publish_wheel_tf>true</publish_wheel_tf>
                
                <odometry_frame>odom</odometry_frame>
                <robot_base_frame>base_footprint</robot_base_frame>
            </plugin>
        </gazebo>
   </xacro:macro>
</robot>
```


## 3.机器人各模块的仿真
#### 添加插件
```
<plugin filename="libgz-sim8-sensors-system.so" name="gz::sim::systems::Sensors">
```
- 在gz sim harmonic中所有仿真都是用同一个插件，然后插件识别`type`来具体实现不同传感器的仿真功能。
- 以下仿真，及数据传输都是由gz sim提供给ros2的
### 3.1 激光雷达传感器仿真
#### gazebo的更新，和以往的版本大大不同
```
旧版本：一体化黑盒
┌─────────────────────────────────────┐
│         gazebo.launch.py            │
│  ├── Gazebo服务器                    │
│  ├── Gazebo GUI                     │
│  ├── ros2_control_node              │
│  ├── robot_state_publisher          │
│  └── spawn_entity                   │
└─────────────────────────────────────┘

新版本：模块化组件
┌──────────────┐  ┌──────────────┐  ┌──────────────┐
│ gz sim       │  │ ros2_control │  │ ros_gz_bridge│
│ (独立进程)   │  │ (独立进程)   │  │ (独立进程)   │
└──────────────┘  └──────────────┘  └──────────────┘
```
#### 数据流路径
```
Gazebo Sim 内部传感器 → 
ros_gz_bridge 桥接 → ROS 2 标准话题
```
#### 发布的具体话题
- 话题名称 : /lidar
- 数据类型 : sensor_msgs/msg/LaserScan
- 发布者节点 : ros_gz_bridge
#### `ros_gz_bridge` 桥接器的作用
- `ros_gz_bridge` 是 Gazebo Sim 和 ROS 2 之间的通信桥梁 ，负责在两种系统之间自动转换和转发数据。
### 3.2 惯性测量传感器仿真
#### IMU 传感器数据流 ：
1. `Gazebo Sim` 内部 : IMU 传感器测量数据，发布到 `/imu (gz.msgs.IMU)`
2. `ros_gz_bridge` : 订阅 Gazebo 话题，转换消息格式，发布到 `/imu (sensor_msgs.msg.Imu)`
3. `ROS 2` 系统 : 其他节点订阅 `/imu` 话题，使用 IMU 数据进行定位、导航等
### 3.3 深度相机传感器仿真
#### 光学坐标系说明
```
相机坐标系 (camera_link)         光学坐标系 (camera_optical_link)
         Z (前)                          X (右)
         ↑                               ↑
         |                               |
         |                               |
    Y (左) ←──┐                     Z (前) ←──┐
              │                               │
              └──→ X (下)                     └──→ Y (下)

转换: rpy="${-pi/2} 0 ${-pi/2}"
```
#### 验证相机
```
# 重新构建
cd ~/arm_ws
colcon build --packages-select my_arm_description
source install/setup.bash

# 运行
ros2 launch my_arm_description spawn_carbot.launch.py

# 查看相机话题
ros2 topic list | grep camera

# 查看图像
ros2 run rqt_image_view rqt_image_view
# 选择 /camera/image_raw

# 查看相机信息
ros2 topic echo /camera/camera_info --once
```


## 4. ros2_control驱动机器人
### 4.1 使用控制器获取信息
- 查看ROS2控制器命令 (jazzy)
```
sudo apt info ros-$ROS_DISTRO-ros2-controllers
```
- 创建carbot.ros2_control.xacro文件
    - 为小车创建了硬件接口`<hardware> < /hardware>`
    - 让gz sim可以识别的插件ros2_control
- 创建.yaml文件，gz sim要识别的控制器管理器
- 启动gz sim后，gazebo会自动启动control_manager节点，然后加载ros2_control插件，然后加载对应配置文件。

- 编写.yaml文件来自定义控制器的名称，并通过`type`来指定控制器的类型
    `joint_state_broadcaster/JointStateBroadCaster`
### 4.2 使用力控制器控制小车轮子
- 在.yaml文件中创建力控制器来驱动小车行走
```
carbot_effort_controller:
      type: effort_controllers/JointGroupEffortController
```
- 配置好力控制器的相关参数
```
carbot_effort_controller:
  ros__parameters:
    joints:
      - left_wheel_joint
      - right_wheel_joint

    command_interfaces:
      - effort

    state_interfaces:
      - position
      - velocity
      - effort
```
### 4.3 使用两轮差速控制器控制小车
- 在.yaml文件中自定义话题的名称，以及其下面要激活的控制器
```
 carbot_diff_drive_controller:
      type: diff_drive_controller/DiffDriveController
```
- 脚本launch文件添加节点的激活就可以了
```
	load_carbot_diff_drive_controller = launch_ros.actions.Node(
        package='controller_manager',
        executable='spawner',
        arguments=['carbot_diff_drive_controller'],
        parameters=[{'use_sim_time': True}],
        output='screen'
    )
```
- 使用ros2自带的键盘控制节点，来测试小车两轮差速控制
```
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```


## 5. 总结--机器人在仿真环境的运行
- `gz sim`启动后会加载main.xacro文件，文件会引用其他.xacro文件的宏
- 这些宏里面有 机器人的结构/机器人的物理特性/`gz sim`会提供的硬件接口
- 相当与 `gz sim` 仿真环境通过硬件接口将数据传输给 `ROS2` 的控制器，而这些控制器会被包装在节点当中（节点名称由我们在.yaml文件中定义了）
- 反之，我们也可以通过这些控制器来驱动`gz sim`中的机器人了
### `carbot.ros2_control.xacro` - 硬件接口定义
- 定义 硬件层面 支持哪些接口
- 告诉ROS 2硬件能做什么（能接收什么命令，能提供什么状态）
- 相当于硬件的"驱动程序接口规范"
### `carbot_ros2_controller.yaml` - 控制器配置
- 定义 软件层面 的控制器行为
- 告诉控制器如何使用硬件接口
- 相当于控制器的"参数配置文件"
### 两个文件如何配合
```
硬件接口定义 (xacro文件)       控制器配置 (yaml文件)
      ↓                            ↓
定义小车能做什么                定义控制器怎么做
      ↓                            ↓
"我能接收速度命令"              "我要用速度接口控制轮子"
"我能提供位置和速度状态"        "轮子间距是0.17米"
```
- **Xacro文件**：定义了物理关节（`joint`），并声明了**要使用** `libgz_ros2_control-system.so` 这个插件。
- **动态库 (`libgz_ros2_control-system.so`)**：它本身不提供具体的“关节接口”，而是作为一个 **“接口工厂”**。它根据YAML文件的配置，在ROS2侧**创建出**与Xacro关节相对应的硬件接口，并负责两端的数据转换。**是Ros2和Gazebo交流的翻译官**
- **YAML文件**：负责**配置**这个工厂，告诉它需要创建哪些接口，以及这些接口分别对应Xacro里的哪个关节。
- 这样的模式便于实现`sim2real`，核心变动就是将`libgazebo_ros2_control.so`变为`libyour_hardware_driver.so`。
- 注意小车的`urdf`文件中为车轮定义的名字要与`control.xacro`中的一致，和`.yaml`配置的名字一致

---
### 整个 `ros2_control` 框架由几个关键的“节点”组成，协同工作完成控制任务[](https://blog.csdn.net/qq_43066145/article/details/128860263)[](https://sir.upc.edu/projects/ros2tutorials/7-control/#available-controllers-for-manipulators)：

|核心组件|它是什么节点？|主要职责|
|---|---|---|
|**控制器管理器 (Controller Manager)**|一个**核心管理节点**（通常名为 `ros2_control_node`）[](https://control.ros.org/foxy/doc/getting_started/getting_started.html)|它像“管家”，负责加载、激活、停止所有其他控制器节点，并匹配硬件接口[](https://www.cnblogs.com/AutumnIsle-blog/p/19124128#commentform)[](https://blog.csdn.net/2302_76303402/article/details/148777590)。|
|**具体控制器 (Controllers)**|**独立的控制器节点**（如 `diff_drive_controller`、`joint_state_broadcaster`）|它们被插件化动态加载，每个节点实现特定算法（如将 `/cmd_vel` 转为轮速），并拥有自己的生命周期[](https://control.ros.org/foxy/doc/getting_started/getting_started.html)[](https://blog.csdn.net/EnHengNa/article/details/157064608)[](https://index.rosdabbler.com/p/andino_control/#galactic)。|
|**硬件组件 (Hardware Component)**|**非 ROS 节点**（是 C++ 插件类）|负责与真实硬件或 Gazebo 仿真通信，提供标准化的状态/命令接口，但它本身不是一个独立的 ROS 节点|

---
### 节点与话题通信关系
```
用户控制端 (ROS 2话题发布)
    ↓ 发布到 /cmd_vel
topic_tools/relay (cmd_vel_relay)
    ↓ 转发到 /
    carbot_diff_drive_controller/
    cmd_vel
controller_manager/spawner → 
carbot_diff_drive_controller
    ↓ 通过硬件接口
gz_ros2_control/GazeboSimSystem (硬
件插件)
    ↓ 通过Gazebo物理引擎
Gazebo Sim仿真环境
    ↓ 返回关节状态
gz_ros2_control/GazeboSimSystem
    ↓ 发布到 /joint_states
joint_state_broadcaster
    ↓ 发布到 /tf, /tf_static
robot_state_publisher
    ↓ 发布到 /odom
carbot_diff_drive_controller
    ↓ 转发到 /odom
topic_tools/relay (odom_relay)
```
### 详细数据流说明 
1. 控制数据流（用户 → 仿真）
```
用户终端:
ros2 topic pub /cmd_vel 
geometry_msgs/msg/Twist "{linear: 
{x: 0.1}, angular: {z: 0.0}}"
    ↓
topic_tools/relay (cmd_vel_relay):
订阅: /cmd_vel
发布: /carbot_diff_drive_controller/
cmd_vel
    ↓
carbot_diff_drive_controller:
订阅: /carbot_diff_drive_controller/
cmd_vel
通过硬件接口发送命令到: 
left_wheel_joint, right_wheel_joint
    ↓
gz_ros2_control/GazeboSimSystem:
接收控制命令，通过Gazebo API驱动关节
    ↓
Gazebo Sim物理引擎:
计算小车运动，更新位置和姿态
```
2. 状态数据流（仿真 → 用户）
```
Gazebo Sim物理引擎:
计算关节状态（位置、速度、力矩）
    ↓
gz_ros2_control/GazeboSimSystem:
读取关节状态，发布到硬件接口
    ↓
joint_state_broadcaster:
订阅硬件接口状态
发布: /joint_states (包含所有关节状态)
    ↓
robot_state_publisher:
订阅: /joint_states
计算并发布: /tf, /tf_static (坐标系变
换)
    ↓
carbot_diff_drive_controller:
计算里程计信息
发布: /carbot_diff_drive_controller/
odom
    ↓
topic_tools/relay (odom_relay):
订阅: /carbot_diff_drive_controller/
odom
发布: /odom (标准里程计话题)
```
### 关键话题列表 输入话题（控制）
- `/cmd_vel` - 用户控制命令（标准Twist消息）
- `/carbot_diff_drive_controller/cmd_vel` - 控制器专用控制命令 输出话题（状态）
- `/joint_states` - 所有关节状态信息
- `/tf , /tf_static` - 坐标系变换
- `/odom `- 里程计信息（标准话题）
- `/carbot_diff_drive_controller/odom` - 控制器专用里程计
- `/robot_description` - 机器人URDF描述 内部话题
- `/controller_manager/*` - 控制器管理相关话题
- `/dynamic_joint_states` - 动态关节状态
### 坐标系关系
```
odom (世界坐标系)
    ↓
base_footprint (小车基座)
    ↓
base_link (小车主体)
    ↓
left_wheel_link, right_wheel_link 
```
### 注意
1. 注意写launch脚本时，要注意几个节点的启动顺序。
    - 尤其是ros2_control_manager与几个控制器的启动。
    - 小车模型加载与其各模块传感器桥接器节点的启动顺序。
```
1. gazebo                    → 启动 Gazebo Sim
2. robot_state_publisher     → 发布机器人描述
3. spawn_entity              → 加载机器人模型到 Gazebo
   
   ↓ 模型加载完成
   
4. ros2_control_node         → 启动控制器管理器
5. lidar_bridge              → 启动激光雷达桥接
6. imu_bridge                → 启动 IMU 桥接
   
   ↓ 控制器管理器启动完成
   
7. joint_state_broadcaster   → 加载关节状态广播器
8. carbot_diff_drive_controller → 加载差速驱动控制器
```

---
# 二、导航基础
### 本质
- 机器人通过传感器获得环境信息如 `/odom, /laserScan`等等，通过他们就可以地图构建了
- `slam`的核心用途就是 **定位+ 建图**
## 1. 使用slam_toolbox完成建图
### 1.1 启动slam_toolbox
```
# 在线异步模式（最常用）
ros2 launch slam_toolbox online_async_launch.py use_sim_time:=true
```
- `slam_toolbox`会发布一个`/map`的话题，可以打开Rviz接收这个话题并显示出来
- `slam_toolbox`的输入数据有两个
    `/scan`话题，订阅来自雷达
    `/odom`话题，订阅获取里面的里程计坐标系，从而到机器人坐标系`base_footprint`的转换

## 2. 使用nav2_map_server保存地图为文件
### 2.1 创建保存地图的包
```
ros2 pkg create carbot_navigation
# 存放地图
mkdir maps
```
## 2.2 在`maps`包下运行命令
```
ros2 run nav2_map_server map_saver_cli -f room
```
- 会在包下自动生成两个文件
    `.pgm`: 单纯的图片文件
    `.yaml`: 数据，做物理的映射

# 3. 使用navigation2
## navigation2的整体框架
- BT导航服务器（使用行为树插件）
    - 这下面有许多子服务器，执行顺序如下：
    - **规划器服务器-全局代价地图**，发送给控制器服务器
    - **控制器服务器-局部代价地图**， 接收规划服务器的信息后由这个服务器来控制机器人行动的（通过/cmd_vel话题），也发送信息给恢复器服务器
    - **恢复器服务器-订阅代价地图-订阅足迹外观**
## 3.1 Navigation2的安装
```
# 1. 设置 ROS 2 环境（将 <ros2-distro> 替换为 jazzy）
source /opt/ros/jazzy/setup.bash

# 2. 安装 Nav2 核心包
sudo apt install ros-jazzy-navigation2
sudo apt install ros-jazzy-nav2-bringup

# 3. 安装 Jazzy 专用的仿真机器人包（用于 Gazebo 测试）
sudo apt install ros-jazzy-nav2-minimal-tb3-sim
sudo apt install ros-jazzy-nav2-minimal-tb4-sim
```
## 3.2 配置nav2参数
- 在config文件夹下配置参数
- 本质时把nav2_bringup包中的yaml文件地参数拿过来用了
```
ros2 launch nav2_bringup navigation_launch.py \
    params_file:=/path/to/your/nav2_params.yaml \
    use_sim_time:=true
```
- 文件中配有`amcl`节点，用于接收`/odom, /scan, /map`的话题来计算机器人的预估位置
## 3.2 开发launch脚本
- 自己要配置好地文件路径（参数）
    sim_real_time设置为true
    config下的.yaml文件
    maps下的.yaml文件
- 本质是把上述三个参数给nav2_bringup包下面的launch.py文件，并启动
- 其次时配置好rviz，并同时启动nav2_bringup包下面地rviz
## 3.3 优化导航速度和膨胀半径
- 在config下的.yaml文件中的`FollowPath`模块下进行修改参数，如各方向坐标的速度或角速度等
- 在`local_costmap`模块下修改膨胀半径(`inflation_radius`), 膨胀半径就是机器人模型的边缘范围。
## 3.4 优化机器人的到点精度
- 在config文件下的.yaml文件中的`general_goal_check`模块下修改参数`_goal_tolerance`来提升小车到点精度

----
# 三、导航应用开发
## 1. 导航的实现流程了解
### 1.1 初始化机器人的位姿
- 新建一个`carbot_application`的包，并在其中创建init_pose的文件来初始化机器人初始位姿
- 具体实现是通过导入nav2的库来实现的
```
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
import rclpy

def main():
    rclpy.init()
    navigator = BasicNavigator()
    initial_pose = PoseStamped()
    initial_pose.header.frame_id = 'map'
    initial_pose.header.stamp = navigator.get_clock().now().to_msg()
    initial_pose.pose.position.x = 0.0
    initial_pose.pose.position.y = 0.0
    initial_pose.pose.orientation.w = 1.0
    navigator.setInitialPose(initial_pose)
    navigator.waitUntilNav2Active()
    rclpy.spin(navigator)
    rclpy.shutdown()
  
if __name__ == '__main__':
    main()
```
### 1.2 通过TF获取机器人的实时位置
- 也是在包下创建新的节点来获取机器人实时位置
- 本质就是监听从`/map`到`base_footprint`的坐标系变换，然后输出到终端中
### 1.3 使用接口完成路点导航
- 可以实现多点导航
- 与单点导航一样通过动作进行调用的，动作服务为`follow_waypoints`
- 创建节点，在节点中写好目标点组
```
# 调用路点导航服务
navigator.followWaypoints(goal_poses)
```

## 2. 自动巡检导航开发
### 2.1 系统架构设计
![[Screenshot 2026-03-29 171935.png]]
#### 需求
1. 机器人能够在不同的目标点间进行循环移动
2. 到达每个目标点后播放对应的语音提示
3. 到达目标点后拍摄实时图像保存至本地

### 2.2 编写巡检控制节点
```
ros2 pkg create auto_patrol_carbot --build-type ament_python --dependencies rcply nav2_simple_commander
```
- 定义一个类继承`BasicNavigator`类，这样就可以在该节点使用导航相关的接口了。                 
- 该类要实现的行为有：
    - 机器人初始位姿（x, y, yaw(机器人朝向)）
    - 通过TF获取当前位姿
    - 通过参数获取目标点集合
    - 导航到目标位姿
- 补充知识：
    - 欧拉角：用于表现机器人旋转，(Roll, Pith, Yaw)分别是 绕x轴，绕y轴，绕z轴
- 参数怎么给？
    - 可以通过config文件夹下的.yaml来配置机器人的目标点参数
    - 在运行节点时记得加载.yaml文件就行
    - ` ros2 run <package_name> <executable_name> --ros-args --params-file            <config_file_path>`
    - 后续也可以再写launch文件来包含这个命令
```
def generate_launch_description():
    # 获取包的路径
    package_dir = get_package_share_directory('auto_patrol_carbot')
    # 构建配置文件路径
    config_path = os.path.join(package_dir, 'config', 'patrol_params_config.yaml')
    
    return LaunchDescription([
        Node(
            package='auto_patrol_carbot',
            executable='auto_patrol_node',
            name='auto_patrol_node',
            parameters=[config_path],
            output='screen'
        )
    ])
```

### 2.3 实现语音播报功能
#### 创建服务接口
- 先创建一个定义接口的包
```
ros2 pkg create carbot_patrol_interfaces --dependencies rosidl_default_generators
```
- 创建服务接口的包（.srv文件），接口文件命名记得大写，符合规范
- 记得修改CMakeList.txt文件和package.xml文件来添加依赖
```
//.txt
rosidl_generate_interfaces(${PROJECT_NAME}
  srv/Speech.srv
)

//.xml
<member_of_group>rosidl_default_generators</member_of_group>
```
#### 实现语音播报逻辑
##### 创建语音服务节点
- 创建`speak.py`节点来实现语音播报逻辑
- 使用 `espeakng` 库将文本转换为语音
```
class Speaker(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.speech_service = self.create_service(
            Speech, 'speech_text', self.speak_text_callback)
        self.speaker = espeakng.Speaker()
        self.speaker.voice = 'zh'

    def speak_text_callback(self, request, response):
        self.get_logger().info('正在朗读 %s' % request.text)
        self.speaker.say(request.text)
        self.speaker.wait()
        response.result = True
        return response
```
##### 创建语音客户端节点
- 就在之前的巡检控制节点文件里面添加就行
```
def speach_text(self, text):
    request = Speech.Request()
    request.text = tex
    future = self.speech_client.call_async(request)
    rclpy.spin_until_future_complete(self, future)
    if future.result() is not None:
       self.get_logger().info('语音合成成功')
    else:
       self.get_logger().error('语音合成失败')
```
#### 编写launch脚本
- 把前面所有的节点启动写入launch中
- launch文件的本质就是获取各个文件的路径（作为命令的参数）
- 然后启动各个ros2命令
- 编写完后记得修改`setup.py`文件和`packages.xml`文件
```
def generate_launch_description():
    package_dir = get_package_share_directory('auto_patrol_carbot')
    config_path = os.path.join(package_dir, 'config', 'patrol_params_config.yaml')
    action_node_patrol = launch_ros.actions.Node(
        package='auto_patrol_carbot',
        executable='auto_patrol_node',
        parameters=[config_path],
        output='screen'
    )

    action_node_speaker = launch_ros.actions.Node(
        package='auto_patrol_carbot',
        executable='speak_node',
        output='screen'
    )

    return launch.LaunchDescription([
        action_node_patrol,
        action_node_speaker,
    ])
```

### 2.4 订阅图像并记录
- 创建一个订阅者，订阅来自相机的图像，并转换为OpenCV的格式
- 接着将图像保存值指定的位置
- 记得在launch文件中添加相机节点
- 记得在launch文件中添加语音播报节点