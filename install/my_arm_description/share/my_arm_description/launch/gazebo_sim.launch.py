#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess, RegisterEventHandler, TimerAction
from launch.event_handlers import OnProcessExit
from launch_ros.actions import Node

# 定义启动文件
def generate_launch_description():
    # 获取当前文件所在目录的绝对路径
    pkg_dir = os.path.dirname(os.path.abspath(__file__))
    # 构建urdf文件路径（使用源目录）
    urdf_path = os.path.join(pkg_dir, '../urdf/carbot/carbot.urdf')
    # 构建world文件路径
    world_path = os.path.join(pkg_dir, '../world/custom_room.sdf')
    # 构建控制器配置文件路径
    controller_config_path = os.path.join(pkg_dir, '../config/carbot_ros2_controller.yaml')

    # 读取URDF文件内容
    with open(urdf_path, 'r') as f:
        robot_description_content = f.read()

    # 定义环境变量
    env = {
        'ROS_DOMAIN_ID': '1',
        'GZ_SIM_SYSTEM_PLUGIN_PATH': '/opt/ros/jazzy/lib',
        'ROS2_CONTROL_PLUGINS_PATH': '/opt/ros/jazzy/lib',
        'LD_LIBRARY_PATH': '/opt/ros/jazzy/lib:' + os.environ.get('LD_LIBRARY_PATH', ''),
    }

    # ========== 1. Robot State Publisher ==========
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{
            'robot_description': robot_description_content,
            'use_sim_time': True
        }],
        additional_env=env,
        output='screen'
    )

    # ========== 2. 启动 Gazebo ==========
    gazebo = ExecuteProcess(
        cmd=['gz', 'sim', '-r', '-s', '-v', '4', world_path],
        output='screen',
        additional_env={
            'GZ_SIM_SYSTEM_PLUGIN_PATH': '/opt/ros/jazzy/lib',
            'LD_LIBRARY_PATH': '/opt/ros/jazzy/lib:' + os.environ.get('LD_LIBRARY_PATH', ''),
            # 关键：强制使用 Ogre 1 并禁用传感器渲染
            'GZ_RENDER_ENGINE': 'ogre',  # 使用 Ogre 1
            'OGRE_RTT_MODE': 'Copy',
            'GZ_SIM_SENSOR_RENDER_THREADS': '0',  # 禁用传感器渲染线程
            'GZ_SIM_SENSOR_RENDERING': '0',  # 禁用传感器渲染
        }
    )

    # ========== 3. Spawn 机器人 (延迟 5 秒启动) ==========
    spawn_entity_cmd = ExecuteProcess(
        cmd=[
            'ros2', 'run', 'ros_gz_sim', 'create',
            '-world', 'custom_room',
            '-name', 'carbot',
            '-file', urdf_path,
            '-x', '0.0',
            '-y', '0.0',
            '-z', '0.1'
        ],
        output='screen',
        additional_env=env
    )

    spawn_entity_node = TimerAction(
        period=5.0,
        actions=[spawn_entity_cmd]
    )

    # ========== 4. 控制器加载节点 ==========
    # 添加静态重映射规则
    odom_remap = Node(
        package='topic_tools',
        executable='relay',
        name='odom_relay',
        parameters=[{'use_sim_time': True}],
        additional_env=env,
        output='screen',
        arguments=['/carbot_diff_drive_controller/odom', '/odom']
    )

    load_joint_state_broadcaster = Node(
        package='controller_manager',
        executable='spawner',
        parameters=[{'use_sim_time': True}],
        additional_env=env,
        output='screen',
        arguments=['joint_state_broadcaster', '--controller-manager', '/controller_manager', '--controller-manager-timeout', '5']
    )

    load_diff_drive_controller = Node(
        package='controller_manager',
        executable='spawner',
        parameters=[
            {'use_sim_time': True}
        ],
        additional_env=env,
        output='screen',
        remappings=[
            ('/carbot_diff_drive_controller/odom', '/odom')
        ],
        arguments=['carbot_diff_drive_controller', '--controller-manager', '/controller_manager', '--controller-manager-timeout', '5']
    )

    # ========== 5. 传感器桥接 ==========
    # 时钟桥接
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/clock@rosgraph_msgs/msg/Clock@gz.msgs.Clock'],
        parameters=[{'use_sim_time': True}],
        additional_env=env,
        output='screen'
    )

    # 激光雷达桥接
    laser_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/world/custom_room/model/carbot/link/laser_link/sensor/laserscan/scan@sensor_msgs/msg/LaserScan@gz.msgs.LaserScan'],
        parameters=[{'use_sim_time': True}],
        additional_env=env,
        remappings=[
            ('/world/custom_room/model/carbot/link/laser_link/sensor/laserscan/scan', '/scan')
        ],
        output='screen'
    )

    # ========== 6. 事件触发的启动顺序 ==========
    # spawn 完成后加载 joint_state_broadcaster
    broadcaster_after_spawn = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=spawn_entity_cmd,
            on_exit=[load_joint_state_broadcaster]
        )
    )

    # joint_state_broadcaster 加载成功后加载 diff_drive_controller
    controller_after_broadcaster = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=load_joint_state_broadcaster,
            on_exit=[load_diff_drive_controller]
        )
    )

    return LaunchDescription([
        # 持续运行的节点
        robot_state_publisher_node,
        gazebo,
        clock_bridge,
        laser_bridge,
        odom_remap,

        # 一次性动作
        spawn_entity_node,

        # 事件处理器
        broadcaster_after_spawn,
        controller_after_broadcaster,
    ])
