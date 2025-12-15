#!/usr/bin/env python3
import time
import socket
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer

# Interfaces
from mmr_interfaces.action import PickAndPlace
from mmr_interfaces.srv import RotateTurret, GetDropPose, MoveArm

# Note: We now talk to xarm_pose_server_min.py via TCP, so no direct SDK needed here.

class PalletizingNode(Node):
    """
    Super Kinetic Controller (Thin Client)
    1. Action: kinetic/pick_and_place (Precise Manipulation)
    2. Service: kinetic/rotate_turret (Camera View Control)
    3. Service: kinetic/get_drop_pose (Slot Management)
    4. Service: kinetic/move_arm (Arbitrary Move)
    
    Communicates with xarm_pose_server_min.py on localhost:30008
    """

    # --- Config ---
    SERVER_IP = '127.0.0.1'
    SERVER_PORT = 30008
    
    # Key Poses (Unit: mm, degree)
    # [x, y, z, r, p, yaw]
    POSE_HOME  = [206, 0, 200, 180, 0, 0]
    
    # Overview Joint Poses (degrees) - safer than Cartesian
    JOINTS_LOOK_LEFT  = [90, -60, -13, 0, -15, 0]
    JOINTS_LOOK_RIGHT = [-90, -60, -13, 0, -15, 0]
    JOINTS_HOME = [0, -50, -20, 0, -20, 0] # Base rotated -90 (Right)
    POSE_LOOK_FWD   = [300,    0, 400, 180, 0, 0]   # Look Forward

    # Pallet Slots (Simple Logic)
    drop_slot_index = 0

    def __init__(self):
        super().__init__('palletizing_node')

        self.sock = None
        self._connect_to_server()

        # Action Server
        self.pnp_server = ActionServer(
            self, PickAndPlace, 'kinetic/pick_and_place', self.pnp_callback
        )

        # Service Servers
        self.srv_turret = self.create_service(
            RotateTurret, 'kinetic/rotate_turret', self.turret_cb
        )
        self.srv_drop = self.create_service(
            GetDropPose, 'kinetic/get_drop_pose', self.drop_pose_cb
        )
        self.srv_move = self.create_service(
            MoveArm, 'kinetic/move_arm', self.move_arm_cb
        )

        self.get_logger().info('PalletizingNode Ready (TCP Client Mode)')
        self.get_logger().info('Please ensure xarm_pose_server_min.py is running!')

    def _connect_to_server(self):
        max_retries = 10
        for i in range(max_retries):
            try:
                self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                self.sock.settimeout(5.0)  # Timeout only for connection attempt
                self.sock.connect((self.SERVER_IP, self.SERVER_PORT))
                self.sock.settimeout(None)  # Remove timeout after successful connection
                self.get_logger().info(f'Connected to xArm Server at {self.SERVER_IP}:{self.SERVER_PORT}')
                return
            except Exception as e:
                self.get_logger().warn(f'Connection failed ({i+1}/{max_retries}): {e}. Retrying in 2s...')
                if self.sock:
                    try:
                        self.sock.close()
                    except:
                        pass
                self.sock = None
                time.sleep(2.0)
        
        self.get_logger().error(f'Failed to connect to xArm Server after {max_retries} attempts.')

    def _send_cmd(self, cmd_str: str):
        if not self.sock:
            self.get_logger().error('Not connected to xArm Server')
            # Try reconnect?
            self._connect_to_server()
            if not self.sock: return

        try:
            msg = cmd_str + "\n"
            self.sock.sendall(msg.encode('utf-8'))
            resp = self.sock.recv(1024).decode('utf-8').strip()
            if resp != 'OK':
                self.get_logger().warn(f'Server response NG or unexpected: {resp}')
        except Exception as e:
            self.get_logger().error(f'Socket error: {e}')
            self.sock.close()
            self.sock = None

    def move_pose(self, pose):
        """ pose: [x,y,z,r,p,y] mm/deg """
        # Server expects "x,y,z,r,p,y"
        # Since the provided server script logic is "Move -> Grip -> Release -> Home",
        # Sending a pose effectively triggers a full cycle in the current server implementation.
        # IF we want discrete moves, the server needs updating.
        # But the instruction was "Separate it", implying usage of the provided file.
        # However, reusing the provided file AS IS for Pick AND Place is impossible because of its hardcoded logic.
        # 
        # I HAVE updated the server file (in previous step check) to handle "GRIPPER_OPEN", "GRIPPER_CLOSE"
        # AND check for valid Poses.
        #
        # Formatting: "x,y,z,r,p,y"
        cmd = ",".join(map(str, pose))
        self.get_logger().info(f'[TCP] Sending Pose: {cmd}')
        self._send_cmd(cmd)

    def gripper(self, open=True):
        cmd = "GRIPPER_OPEN" if open else "GRIPPER_CLOSE"
        self.get_logger().info(f'[TCP] Sending Gripper: {cmd}')
        self._send_cmd(cmd)

    # --- Service Callbacks ---

    def turret_cb(self, request, response):
        """ Rotate xArm to look Left/Right using Joint angles """
        d = request.direction

        if d == RotateTurret.Request.LEFT:
            target = self.JOINTS_LOOK_LEFT
            lbl = "LEFT"
        elif d == RotateTurret.Request.RIGHT:
            target = self.JOINTS_LOOK_RIGHT
            lbl = "RIGHT"
        else:  # FORWARD (treat as HOME)
            target = self.JOINTS_HOME
            lbl = "HOME"
        
        self.get_logger().info(f'[Turret] Rotating to {lbl}...')
        self.move_joints(target)
        
        # Query actual position after movement
        current_pose = self.get_current_pose()
        if current_pose:
            response.current_pose = current_pose  # Full [x,y,z,r,p,y]
            self.get_logger().info(f'[Turret] Moved to {lbl}, pose: XYZ={current_pose[:3]}, RPY={current_pose[3:6]}')
        else:
            response.current_pose = []
            self.get_logger().warn(f'[Turret] Failed to get position after {lbl}')
        
        response.success = True
        return response
    
    def move_joints(self, angles):
        """ angles: [j1,j2,j3,j4,j5,j6] degrees """
        # Server expects "JOINT:j1,j2,j3,j4,j5,j6"
        cmd = "JOINT:" + ",".join(map(str, angles))
        self.get_logger().info(f'[TCP] Sending Joints: {cmd}')
        self._send_cmd(cmd)
    
    def get_current_pose(self):
        """ Query current arm position from server """
        if not self.sock:
            self.get_logger().error('Not connected to xArm Server')
            return None
        
        try:
            self.sock.sendall(b"GET_POSE\n")
            resp = self.sock.recv(1024).decode('utf-8').strip()
            if resp.startswith("POSE:"):
                pose_str = resp[5:]  # Remove "POSE:"
                pose = [float(x) for x in pose_str.split(",")]
                self.get_logger().info(f'[TCP] Current pose: {pose[:3]} RPY: {pose[3:6]}')
                return pose[:6]  # Return [x, y, z, roll, pitch, yaw]
            else:
                self.get_logger().warn(f'Failed to get pose: {resp}')
                return None
        except Exception as e:
            self.get_logger().error(f'Get pose error: {e}')
            return None

    def drop_pose_cb(self, request, response):
        """ Calculate where to put the object based on tag """
        idx = self.drop_slot_index % 4
        self.drop_slot_index += 1
        
        # Base drop area: x=-200mm (behind base), y=0
        base_x = -0.2
        col = idx % 2
        row = idx // 2
        
        tx = base_x - (row * 0.1) # -0.2, -0.3
        ty = -0.1 + (col * 0.2)   # -0.1, +0.1
        tz = 0.1                  # height
        
        response.success = True
        response.x = tx
        response.y = ty
        response.z = tz
        self.get_logger().info(f'[DropSolver] Tag="{request.tag}" -> Slot {idx}: ({tx:.2f}, {ty:.2f})')
        return response

    def move_arm_cb(self, request, response):
        """ Explicitly move arm to arbitrary pose (x,y,z,r,p,y) """
        pose = list(request.pose)
        if len(pose) != 6:
            msg = f"Invalid pose length: {len(pose)}"
            self.get_logger().error(msg)
            response.success = False
            return response

        self.get_logger().info(f'[MoveArm] Request received. Target: {pose}')
        self.move_pose(pose)
        response.success = True
        return response

    # --- Action Callback ---

    def pnp_callback(self, goal_handle):
        """ Pick (A) -> Place (B) """
        pick = goal_handle.request.pick_pose   # [x,y,z] or [x,y,z,r,p,y] unit: mm/degree
        place = goal_handle.request.place_pose # [x,y,z] unit: mm

        self.get_logger().info(f'[PnP] Start: Pick({pick}) -> Place({place})')
        fb = PickAndPlace.Feedback()
        fb.status = "Approaching Pick"
        goal_handle.publish_feedback(fb)

        # 1. Extract coordinates (already in mm)
        p_x, p_y, p_z = pick[0], pick[1], pick[2]
        d_x, d_y, d_z = place[0], place[1], place[2]
        
        # Use RPY from pick_pose if provided (aligned mode)
        if len(pick) >= 6:
            p_r, p_p, p_yaw = pick[3], pick[4], pick[5]
            self.get_logger().info(f'[PnP] Using aligned orientation: RPY=({p_r:.1f}, {p_p:.1f}, {p_yaw:.1f})')
        else:
            # Default: look down
            p_r, p_p, p_yaw = 180, 0, 0
            self.get_logger().info(f'[PnP] Using default orientation: RPY=(180, 0, 0)')

        # 2. Pick Sequence
        # Approach (z + 50mm)
        self.move_pose([p_x, p_y, p_z + 50, p_r, p_p, p_yaw])
        # Down
        self.move_pose([p_x, p_y, p_z, p_r, p_p, p_yaw])
        # Grip
        self.gripper(open=False)
        # Up
        self.move_pose([p_x, p_y, p_z + 150, p_r, p_p, p_yaw])

        fb.status = "Moving to Place"
        fb.progress = 50.0
        goal_handle.publish_feedback(fb)

        # 3. Place Sequence
        # Approach (z + 50mm)
        self.move_pose([d_x, d_y, d_z + 50, 180, 0, 0])
        # Down
        self.move_pose([d_x, d_y, d_z,      180, 0, 0])
        # Ungrip
        self.gripper(open=True)
        # Up
        self.move_pose([d_x, d_y, d_z + 50, 180, 0, 0])

        # 4. Finish
        self.move_pose(self.POSE_HOME)
        
        goal_handle.succeed()
        result = PickAndPlace.Result()
        result.success = True
        result.message = "PnP Complete"
        return result

def main(args=None):
    rclpy.init(args=args)
    node = PalletizingNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt: pass
    finally:
        if node.sock: node.sock.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
