from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="mimi_head",
            executable="mimi_camera",
            name="mimi_camera"
        ),
        Node(
            package="mimi_head",
            executable="mimi_monitor",
            name="mimi_monitor"
        )
])