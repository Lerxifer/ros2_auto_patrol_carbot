import os
import launch
import launch_ros
from ament_index_python.packages import get_package_share_directory
from launch.launch_description_sources import PythonLaunchDescriptionSource


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
