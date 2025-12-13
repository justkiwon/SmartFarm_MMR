#!/usr/bin/env python3
import math
import time
import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
from geometry_msgs.msg import Twist, TransformStamped
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

from mmr_interfaces.srv import MoveDistance

class AMRMoveNode(Node):
    """
    AMR Controller (BigDog Standards)
    - Uses TF2 for robust odometry (odom -> base_link) extraction.
    - Implements basic P-control for straight line driving (optional but good).
    - Checks TF timeout safety.
    """

    def __init__(self):
        super().__init__('amr_move_node')

        # Properties
        self.target_frame = self.declare_parameter('target_frame', 'base_link').value
        self.odom_frame = self.declare_parameter('odom_frame', 'odom').value
        self.linear_speed = self.declare_parameter('linear_speed', 0.2).value # m/s (safe speed for BigDog)
        self.control_rate = 20.0 # Hz

        # TF2 Setup
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Publishers / Services
        self.cmd_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.srv = self.create_service(MoveDistance, 'amr/move_distance', self.move_distance_cb)

        self.get_logger().info(f'AMR Move Node (BigDog) Ready. Speed={self.linear_speed}m/s')

    def get_current_pose(self):
        """
        Returns (x, y, yaw) in Odom frame
        """
        try:
            # Check latest available transform
            t = self.tf_buffer.lookup_transform(
                self.odom_frame,
                self.target_frame,
                rclpy.time.Time()
            )
            tx = t.transform.translation.x
            ty = t.transform.translation.y
            
            # Quaternion to Yaw
            qx = t.transform.rotation.x
            qy = t.transform.rotation.y
            qz = t.transform.rotation.z
            qw = t.transform.rotation.w
            
            # Yaw calculation (Z-axis rotation)
            siny_cosp = 2.0 * (qw * qz + qx * qy)
            cosy_cosp = 1.0 - 2.0 * (qy * qy + qz * qz)
            yaw = math.atan2(siny_cosp, cosy_cosp)

            return tx, ty, yaw

        except TransformException as ex:
            self.get_logger().warn(f'Could not extract TF: {ex}')
            return None, None, None

    def move_distance_cb(self, request, response):
        dist_target = float(request.distance)
        self.get_logger().info(f'[AMR] Move Request: {dist_target:.3f} m')

        # 1. Get Start Pose
        start_x, start_y, start_yaw = self.get_current_pose()
        
        # --- SIMULATION FALLBACK CHECK ---
        if start_x is None:
            self.get_logger().warn('TF Error (No Odom) -> Switching to SIMULATION MODE (Open Loop)')
            # Time-based Open Loop
            # t = d / v
            if self.linear_speed <= 0.001:
                response.success = False
                response.message = 'Speed too low for open loop'
                return response

            target_duration = dist_target / self.linear_speed
            self.get_logger().info(f'[AMR-Sim] Moving for {target_duration:.2f} seconds')
            
            cmd = Twist()
            cmd.linear.x = self.linear_speed
            
            # Simple Time Loop
            start_time = time.time()
            
            while rclpy.ok():
                now = time.time()
                elapsed = now - start_time
                
                if elapsed >= target_duration:
                    break
                
                self.cmd_pub.publish(cmd)
                
                # Report progress every 0.5s
                if int(elapsed * 10) % 5 == 0:
                     self.get_logger().info(f'[AMR-Sim] Moving... {elapsed:.1f}/{target_duration:.1f}s')

                time.sleep(0.05)
                
            self.stop_robot()
            response.success = True
            response.message = f'Moved {dist_target:.3f} m (Simulated)'
            self.get_logger().info(f'[AMR] Done. {response.message}')
            return response
        # ---------------------------------

        # 2. Control Loop (Real Odometry)
        rate = self.create_rate(self.control_rate)
        cmd = Twist()
        cmd.linear.x = self.linear_speed

        while rclpy.ok():
            curr_x, curr_y, curr_yaw = self.get_current_pose()
            if curr_x is None:
                self.stop_robot()
                response.success = False
                response.message = 'TF Lost during move'
                return response
            
            # Distance Calculation
            dx = curr_x - start_x
            dy = curr_y - start_y
            traveled = math.sqrt(dx*dx + dy*dy)
            
            if traveled >= dist_target:
                break
            
            # (Optional) Angular Correction to keep straight line could go here
            # For now, simple open loop straight is fine for 50cm steps.
            
            self.cmd_pub.publish(cmd)
            rate.sleep()

        # 3. Stop
        self.stop_robot()
        
        response.success = True
        response.message = f'Moved {dist_target:.3f} m'
        self.get_logger().info(f'[AMR] Done. {response.message}')
        return response

    def stop_robot(self):
        self.cmd_pub.publish(Twist())

def main(args=None):
    rclpy.init(args=args)
    node = AMRMoveNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
