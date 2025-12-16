#!/usr/bin/env python3
import math
import time
import requests

import rclpy
from rclpy.node import Node

from mmr_interfaces.srv import MoveDistance


class AMRMoveNode(Node):
    """
    AMR HTTP Controller Node
    - Service: /amr/move_distance (mmr_interfaces/srv/MoveDistance)
    - Sends move command via HTTP: POST {HOST}/cmd/move
    - Monitors pose via HTTP:      GET  {HOST}/reeman/pose
    - Returns when reached/timeout/stopped
    """

    def __init__(self):
        super().__init__("amr_move_node")

        # ===== Parameters =====
        self.host = self.declare_parameter("host", "http://192.168.0.8").value
        self.move_path = self.declare_parameter("move_path", "/cmd/move").value
        self.pose_path = self.declare_parameter("pose_path", "/reeman/pose").value

        # move tuning
        self.speed = float(self.declare_parameter("speed", 0.1).value)  # server speed parameter
        self.poll_hz = float(self.declare_parameter("poll_hz", 20.0).value)
        self.timeout_sec = float(self.declare_parameter("timeout_sec", 60.0).value)

        # reach 판단 허용오차 (cm)
        self.eps_cm = float(self.declare_parameter("eps_cm", 5.0).value)  # 짧은 거리면 0.3~0.5 추천 -> 2.0으로 완화

        # 정지 판정(윈도우 동안 거의 안 움직이면 멈춘 걸로)
        self.stopped_window_sec = float(self.declare_parameter("stopped_window_sec", 1.0).value)
        self.stopped_eps_cm = float(self.declare_parameter("stopped_eps_cm", 0.5).value)

        self.move_url = f"{self.host}{self.move_path}"
        self.pose_url = f"{self.host}{self.pose_path}"

        # ===== ROS Service =====
        self.srv = self.create_service(MoveDistance, "amr/move_distance", self.move_distance_cb)

        self.get_logger().info(
            f"[AMR-HTTP] Ready. host={self.host} move={self.move_path} pose={self.pose_path} "
            f"speed={self.speed} poll_hz={self.poll_hz} eps_cm={self.eps_cm}"
        )

    # ---------------- HTTP helpers ----------------
    def get_pose(self) -> dict:
        """
        Returns dict: {'x': float, 'y': float, 'theta': float}
        """
        r = requests.get(self.pose_url, timeout=3)
        r.raise_for_status()
        p = r.json()

        # 최소 방어: 키가 없으면 예외
        if not all(k in p for k in ("x", "y", "theta")):
            raise ValueError(f"Pose JSON missing keys: {p}")

        return p

    def post_move(self, distance_cm: float, direction: int, speed: float) -> tuple[int, dict | None, str]:
        """
        Sends move command.
        Returns (status_code, json_or_none, text)
        """
        # Fix: Cast distance to int (server rejects float "50.0")
        payload = {
            "distance": int(distance_cm), 
            "direction": int(direction), 
            "speed": float(speed)
        }
        
        r = requests.post(
            self.move_url,
            json=payload,
            timeout=30,
        )
        try:
            data = r.json()
        except Exception:
            data = None
        return r.status_code, data, r.text

    def wait_until_reached(
        self,
        distance_cm: float,
        eps_cm: float,
        poll_hz: float,
        timeout_sec: float,
        stopped_window_sec: float,
        stopped_eps_cm: float,
    ) -> tuple[bool, str, dict, float]:
        """
        Returns:
          (ok, reason, last_pose, final_dist_cm)

        reason:
          - "reached"
          - "stopped_before_reach"
          - "timeout"
          - "pose_error"
        """
        target_m = distance_cm / 100.0
        eps_m = eps_cm / 100.0
        dt = 1.0 / max(1e-6, poll_hz)

        try:
            start = self.get_pose()
        except Exception as e:
            return False, f"pose_error: {e}", {}, 0.0

        x0, y0 = float(start["x"]), float(start["y"])
        self.get_logger().info(f"[AMR-HTTP] START pose: {start}")

        t0 = time.time()
        hist = []  # (t, x, y)

        last_pose = start
        final_dist_cm = 0.0

        while rclpy.ok():
            # timeout check
            now = time.time()
            if now - t0 > timeout_sec:
                return False, "timeout", last_pose, final_dist_cm

            # read pose
            try:
                p = self.get_pose()
            except Exception as e:
                return False, f"pose_error: {e}", last_pose, final_dist_cm

            last_pose = p
            x, y = float(p["x"]), float(p["y"])

            dist_m = math.hypot(x - x0, y - y0)
            final_dist_cm = dist_m * 100.0

            self.get_logger().info(
                f"[AMR-HTTP] cur=({x:.3f},{y:.3f}) dist={dist_m:.3f}m / target={target_m:.3f}m"
            )

            # reached
            if dist_m >= (target_m - eps_m):
                return True, "reached", last_pose, final_dist_cm

            # stopped detection
            # [Fix] 3-sec Grace Period
            if (now - t0) > 3.0:
                hist.append((now, x, y))
                while hist and (now - hist[0][0] > stopped_window_sec):
                    hist.pop(0)

                if len(hist) >= 2 and (hist[-1][0] - hist[0][0] > 0.5):
                    moved_m = 0.0
                    for i in range(1, len(hist)):
                        moved_m += math.hypot(hist[i][1] - hist[i - 1][1], hist[i][2] - hist[i - 1][2])

                    if moved_m <= (stopped_eps_cm / 100.0):
                        return False, "stopped_before_reach", last_pose, final_dist_cm

            time.sleep(dt)

        return False, "ros_shutdown", last_pose, final_dist_cm

    # ---------------- ROS service callback ----------------
    def move_distance_cb(self, request, response):
        """
        request.distance: meters (기존 네 노드 기준 그대로)
        - +면 전진, -면 후진으로 처리 (direction 자동 결정)
        """
        dist_m = float(request.distance)
        if abs(dist_m) < 1e-6:
            response.success = True
            response.message = "distance ~ 0, nothing to do"
            return response

        # distance(m) -> cm
        distance_cm = abs(dist_m) * 100.0

        # direction 결정 (너 예시: direction=0/1)
        # 네가 사용한 코드에서 direction=1을 썼으니,
        # 여기서는 관례로: +distance => direction=0, -distance => direction=1 로 잡음
        direction = 1 if dist_m > 0 else 0  

        self.get_logger().info(
            f"[AMR-HTTP] Move Request: {dist_m:.3f} m -> {distance_cm:.1f} cm, direction={direction}, speed={self.speed}"
        )

        # 1) POST move
        try:
            code, data, text = self.post_move(distance_cm=distance_cm, direction=direction, speed=self.speed)
        except Exception as e:
            response.success = False
            response.message = f"HTTP move error: {e}"
            return response

        self.get_logger().info(f"[AMR-HTTP] POST /cmd/move => {code} {text}")

        accepted = (code == 200) and isinstance(data, dict) and (data.get("status") == "success")
        if not accepted:
            response.success = False
            response.message = f"Move not accepted. code={code}, data={data}, text={text}"
            return response

        # 2) wait until reached
        ok, reason, last_pose, final_dist_cm = self.wait_until_reached(
            distance_cm=distance_cm,
            eps_cm=self.eps_cm,
            poll_hz=self.poll_hz,
            timeout_sec=self.timeout_sec,
            stopped_window_sec=self.stopped_window_sec,
            stopped_eps_cm=self.stopped_eps_cm,
        )

        response.success = bool(ok)
        response.message = (
            f"{reason} | target={distance_cm:.1f}cm, final={final_dist_cm:.2f}cm, last_pose={last_pose}"
        )

        self.get_logger().info(f"[AMR-HTTP] Done. {response.message}")
        return response


def main(args=None):
    rclpy.init(args=args)
    node = AMRMoveNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
