import math
import requests
import time

HOST = "http://192.168.0.8"

MOVE_URL = f"{HOST}/cmd/move"
POSE_URL = f"{HOST}/reeman/pose"

def get_pose():
    r = requests.get(POSE_URL, timeout=3)
    r.raise_for_status()
    return r.json()  # {'x':..., 'y':..., 'theta':...}

def post_move(distance_cm: float, direction: int = 0, speed: float = 0.1):
    r = requests.post(
        MOVE_URL,
        json={"distance": distance_cm, "direction": direction, "speed": speed},
        timeout=30
    )
    # 서버가 JSON도 주면 읽어서 status 확인
    try:
        data = r.json()
    except Exception:
        data = None
    return r.status_code, r.text, data

def wait_until_reached(distance_cm: float,             # 목표 이동거리(cm). 예: 10 -> 10cm
                       eps_cm: float = 0.1,            # 도착 허용오차(cm). dist >= (target - eps)면 도착 처리
                       poll_hz: float = 20.0,          # pose를 몇 Hz로 읽을지(폴링 주기). 10이면 0.1초마다 읽음   
                       timeout_sec: float = 60.0,      # 최대 대기 시간(초). 넘으면 timeout으로 종료
                       stopped_window_sec: float = 1.0,# 정지 판정 윈도우(초). 최근 이 시간 동안 움직임 누적 계산
                       stopped_eps_cm: float = 0.1):   # 정지 판정 허용 이동(cm). 윈도우 동안 이 값 이하로 움직이면 "정지"

    """
    - 시작 pose 저장
    - 직선거리로 목표 도달 판정
    - 추가로 '정지 판정'도 함께 (움직임이 거의 없으면 True로 종료)
    """
    target_m = distance_cm / 100.0
    eps_m = eps_cm / 100.0

    start = get_pose()
    x0, y0 = start["x"], start["y"]
    print("START:", start)

    dt = 1.0 / poll_hz
    t0 = time.time()

    # 정지 판정용 누적(최근 window 동안 이동거리)
    hist = []  # (t, x, y)

    while True:
        p = get_pose()
        x, y = p["x"], p["y"]

        # 목표거리(시작점 대비 직선거리)
        dist = math.hypot(x - x0, y - y0)
        print(f"cur=({x:.3f},{y:.3f}) dist={dist:.3f}m / target={target_m:.3f}m")

        if dist >= (target_m - eps_m):
            return True, "reached", p

        # 정지 판정(최근 stopped_window_sec 동안 이동이 거의 없으면)
        now = time.time()
        hist.append((now, x, y))
        # 오래된 샘플 제거
        while hist and (now - hist[0][0] > stopped_window_sec):
            hist.pop(0)

        if len(hist) >= 2:
            moved = 0.0
            for i in range(1, len(hist)):
                moved += math.hypot(hist[i][1] - hist[i-1][1], hist[i][2] - hist[i-1][2])
            if moved <= (stopped_eps_cm / 100.0):
                return False, "stopped_before_reach", p

        if now - t0 > timeout_sec:
            return False, "timeout", p

        time.sleep(dt)

if __name__ == "__main__":
    # 1) move 명령
    #distance_cm=50
    distance_cm=50
    code, text, data = post_move(distance_cm=distance_cm, direction=0,speed=0.1)
    print(code, text)

    # 2) 200 + status success면 체크 루프 진입
    ok_status = (code == 200) and (isinstance(data, dict) and data.get("status") == "success")
    if ok_status:
        ok, reason, last_pose = wait_until_reached(distance_cm=distance_cm, eps_cm=5.0)
        print("DONE:", ok, reason, "LAST:", last_pose)
    else:
        print("Move command not accepted:", data)
