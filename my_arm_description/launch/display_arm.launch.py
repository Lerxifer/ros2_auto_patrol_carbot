import launch
import launch_ros
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    # 获取包的共享目录路径
    pkg_share = get_package_share_directory('my_arm_description')
    default_urdf_path = os.path.join(pkg_share, 'urdf', 'carbot', 'carbot.urdf.xacro')
    default_rviz_config_path = os.path.join(pkg_share, 'config', 'display_arm_model.rviz')

    # 声明URDF文件路径参数，方便修改
    action_declare_model = launch.actions.DeclareLaunchArgument(
        name = 'model',
        default_value=str(default_urdf_path),
        description='URDF/XACRO file path'
    )

    # 通过文件路径，获取内容，并转换为参数值对象，以供传入robot_state_publisher
    substitution_command_result = launch.substitutions.Command(['xacro ', launch.substitutions.LaunchConfiguration('model')])
    arm_description_value = launch_ros.descriptions.ParameterValue(substitution_command_result, value_type=str)

    # 启动robot_state_publisher节点
    robot_state_publisher_node = launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': arm_description_value}]
    )
    
    # 启动joint_state_publisher节点
    joint_state_publisher_node = launch_ros.actions.Node(
        package='joint_state_publisher',
        executable='joint_state_publisher'
    )
    
    # 启动rviz2节点
    rviz2_node = launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', default_rviz_config_path]
    )
    
    return launch.LaunchDescription([
        action_declare_model,
        # 启动节点
        robot_state_publisher_node,
        joint_state_publisher_node,
        rviz2_node
    ])
