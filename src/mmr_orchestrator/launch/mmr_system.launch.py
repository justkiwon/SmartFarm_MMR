from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition

def generate_launch_description():
    arg_run_orch = DeclareLaunchArgument(
        'run_orchestrator',
        default_value='true',
        description='Whether to run the orchestrator node (set to false for debugging)'
    )

    # 1. xArm Pose Node (Handles Arm & Sequence)
    xarm_node = Node(
        package='kinetic',
        executable='xarm_pose_node',
        name='xarm_pose_node',
        output='screen'
    )
    
    # 2. AMR Controller
    amr_node = Node(
        package='amr_controller',
        executable='amr_move_node',
        name='amr_move_node',
        output='screen'
    )

    # 3. Vision API Node
    vision_node = Node(
        package='vision',
        executable='vision_capture_node',
        name='vision_capture_node',
        output='screen'
    )

    # 4. Palletizing Node (Slot Logic Only)
    pallet_node = Node(
        package='kinetic',
        executable='palletizing_node',
        name='palletizing_node',
        output='screen'
    )

    # 5. MMR Orchestrator
    orchestrator_node = Node(
        package='mmr_orchestrator',
        executable='mmr_orchestrator_node',
        name='mmr_orchestrator',
        output='screen',
        condition=IfCondition(LaunchConfiguration('run_orchestrator'))
    )

    return LaunchDescription([
        arg_run_orch,
        xarm_node,
        amr_node,
        vision_node,
        pallet_node,
        orchestrator_node
    ])
