# xarm_pose_server_min.py
import socket, time
import sys

# Force system path for xarm if needed, though this script is likely run with the production venv
sys.path.append('/home/pandora/dev/strawberry/shared/venvs/.venv_production/lib/python3.10/site-packages')

try:
    from xarm.wrapper import XArmAPI
except ImportError:
    print("❌ xArm SDK not found. Please check your venv or sys.path")
    sys.exit(1)

ROBOT_IP = '192.168.10.217'
HOST = '0.0.0.0'
PORT = 30008

# Motion params
SPEED = 100
ACC   = 1000

# Gripper params
GRIP_CLOSE_POS = 0        # 닫힘
GRIP_OPEN_POS  = 300      # 열림 (제공 예제 기준)
GRIP_SPEED     = 5000
WAIT_BEFORE_GRIP = 0.3
WAIT_AFTER_GRIP  = 0.3

HOME_POSE = [206, 0, 200, 180, 0, 0]  # Deprecated - using joints now
HOME_JOINTS = [0, -50, -20, 0, -20, 0]  # degrees

def parse_pose(line: str):
    parts = [t.strip() for t in line.split(",") if t.strip()]
    if len(parts) != 6:
        return None
    try:
        return tuple(map(float, parts))  # x,y,z,r,p,yaw
    except ValueError:
        return None

def gripper_close(arm) -> bool:
    try:
        code = arm.set_gripper_position(GRIP_CLOSE_POS, wait=True, speed=GRIP_SPEED, auto_enable=True)
        if code != 0:
            print(f"⚠️  Gripper close failed: code={code}")
            return False
        print("🤏 Gripper closed")
        return True
    except Exception as e:
        print("❌ Gripper exception:", e)
        return False

def gripper_open(arm) -> bool:
    try:
        code = arm.set_gripper_position(GRIP_OPEN_POS, wait=True, speed=GRIP_SPEED, auto_enable=True)
        if code != 0:
            print(f"⚠️  Gripper open failed: code={code}")
            return False
        print("👐 Gripper opened")
        return True
    except Exception as e:
        print("❌ Gripper exception:", e)
        return False

def goto_home(arm):
    try:
        # Ensure robot is ready
        arm.set_mode(0)
        arm.set_state(0)
        time.sleep(0.5)
        
        # Use joint angles (safer than Cartesian)
        ret = arm.set_servo_angle(angle=HOME_JOINTS, speed=50, wait=True)
        if ret < 0:
            print(f"⚠️  HOME move failed ({ret}), retrying...")
            arm.clean_error()
            arm.set_state(0)
            time.sleep(0.3)
            ret = arm.set_servo_angle(angle=HOME_JOINTS, speed=50, wait=True)
            if ret < 0:
                print(f"⚠️  HOME retry also failed ({ret}), continuing anyway...")
        print("🏠 Returned HOME")
    except Exception as e:
        print(f"⚠️  HOME exception: {e}, continuing...")

def main():
    print("[INFO] Connecting to xArm...")
    arm = XArmAPI(ROBOT_IP)
    arm.motion_enable(True)
    arm.clean_warn(); arm.clean_error()
    arm.set_mode(0); arm.set_state(0)
    time.sleep(0.3)

    # (옵션) 그리퍼 준비: 실패해도 계속 진행
    try:
        arm.set_gripper_enable(True)
        arm.set_gripper_mode(0)  # position mode
        print("[INFO] Gripper ready")
    except Exception as e:
        print("[WARN] Gripper init skipped/failed:", e)

    # 시작 시 HOME 이동 후 그리퍼 오픈
    goto_home(arm)
    gripper_open(arm)
    print("[INFO] xArm Ready ✅")

    # TCP 서버
    srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    srv.bind((HOST, PORT))
    srv.listen(1)
    srv.settimeout(None)
    print(f"✅ TCP Server listening on {HOST}:{PORT}")

    try:
        while True:
            conn, addr = srv.accept()
            print(f"🔗 Connected: {addr}")
            conn.settimeout(None)  # Explicitly reset timeout for accepted connection
            with conn:
                buf = ""
                while True:
                    chunk = conn.recv(4096)
                    if not chunk:
                        break
                    buf += chunk.decode("utf-8","ignore")
                    while "\n" in buf:
                        line, buf = buf.split("\n", 1)
                        line = line.strip()
                        if not line:
                            continue
                        print("📨 RX:", line)
                        
                        # Check for JOINT command
                        if line.startswith("JOINT:"):
                            try:
                                joint_str = line[6:]  # Remove "JOINT:"
                                joints = [float(x.strip()) for x in joint_str.split(",")]
                                if len(joints) != 6:
                                    conn.sendall(b"NG\n"); print("⚠️  Invalid joint count")
                                    continue
                                
                                ret = arm.set_servo_angle(angle=joints, speed=50, wait=True)
                                if ret < 0:
                                    print(f"⚠️  Joint move failed: {ret}")
                                    conn.sendall(b"NG\n")
                                else:
                                    print(f"✅ Reached joint target")
                                    conn.sendall(b"OK\n")
                            except Exception as e:
                                conn.sendall(b"NG\n"); print("❌ Joint cmd error:", e)
                            continue
                        
                        # Check for GET_POSE command
                        if line == "GET_POSE":
                            try:
                                code, pos = arm.get_position()
                                if code == 0:
                                    # pos = [x, y, z, roll, pitch, yaw]
                                    pose_str = ",".join(map(str, pos))
                                    conn.sendall(f"POSE:{pose_str}\n".encode())
                                    print(f"📍 Current pose: {pos[:3]}")
                                else:
                                    conn.sendall(b"NG\n")
                            except Exception as e:
                                conn.sendall(b"NG\n"); print("❌ Get pose error:", e)
                            continue
                        
                        # Check for MOVEL_TOOL command
                        if line.startswith("MOVEL_TOOL:"):
                            try:
                                pose_str = line[11:]
                                parts = [float(x.strip()) for x in pose_str.split(",")]
                                if len(parts) != 6:
                                    conn.sendall(b"NG\n"); print("⚠️  Invalid tool pose count")
                                    continue
                                x, y, z, r, p, yaw = parts
                                
                                # Move Relative to Tool
                                ret = arm.set_position(x=x, y=y, z=z, roll=r, pitch=p, yaw=yaw,
                                                    speed=SPEED, acc=ACC, wait=True, relative=True)
                                
                                # Add explicit wait to ensure motion settles
                                time.sleep(0.5)
                                
                                if ret < 0:
                                    print(f"⚠️  Tool Move failed: {ret}")
                                    conn.sendall(b"NG\n")
                                else:
                                    print(f"✅ Reached Tool target")
                                    conn.sendall(b"OK\n")
                            except Exception as e:
                                conn.sendall(b"NG\n"); print("❌ Tool cmd error:", e)
                            continue

                        pose = parse_pose(line)
                        if not pose:
                            # Not a pose, Check Simple Commands
                            if line == "GRIPPER_OPEN":
                                gripper_open(arm)
                                conn.sendall(b"OK\n")
                            elif line == "GRIPPER_CLOSE":
                                gripper_close(arm)
                                conn.sendall(b"OK\n")
                            else:    
                                conn.sendall(b"NG\n"); print("⚠️  Invalid format")
                            continue

                        x,y,z,r,p,yaw = pose
                        try:
                            # 1) 목표 좌표 이동
                            ret = arm.set_position(x=x, y=y, z=z,
                                             roll=r, pitch=p, yaw=yaw,
                                             speed=SPEED, acc=ACC, wait=True)
                            if ret < 0:
                                print(f"⚠️  Move failed: {ret}")
                                conn.sendall(b"NG\n")
                            else:
                                print("✅ Reached target")
                                conn.sendall(b"OK\n")
                        except Exception as e:
                            conn.sendall(b"NG\n"); print("❌ Sequence error:", e)
            print("🔌 Disconnected")
    except KeyboardInterrupt:
        print("\n[STOP] KeyboardInterrupt")
    finally:
        try:
            arm.disconnect()
        except Exception as e:
            print(f"[WARN] Disconnect failed: {e}")

if __name__ == "__main__":
    main()
