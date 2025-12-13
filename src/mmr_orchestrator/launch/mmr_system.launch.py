from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='amr_controller',
            executable='amr_move_node',
            name='amr_move_node',
            output='screen',
        ),
        Node(
            package='vision',
            executable='vision_capture_node',
            name='vision_capture_node',
            output='screen',
        ),
        Node(
            package='kinetic',
            executable='palletizing_node',
            name='palletizing_node',
            output='screen',
        ),
        Node(
            package='mmr_orchestrator',
            executable='mmr_orchestrator_node',
            name='mmr_orchestrator',
            output='screen',
            parameters=[
                {'step_distance': 0.5},
                {'total_distance': 5.0},
            ],
        ),
    ])
