from collections import deque

### input
nums = list(map(int, input().split()))

### initialize
INDEX = 0
SCORE = 1
NEXTS = 2

board = (
    (0, 0, (1,)), # 시작
    (1, 2, (2,)),
    (2, 4, (3,)),
    (3, 6, (4,)),
    (4, 8, (5,)),
    (5, 10, (13, 6)),    # 10점 칸
    (6, 13, (7,)),
    (7, 16, (8,)),
    (8, 19, (9,)),
    (9, 25, (10,)),
    (10, 30, (11,)),
    (11, 35, (12,)),
    (12, 40, (32,)),
    (13, 12, (14,)),
    (14, 14, (15,)),
    (15, 16, (16,)),
    (16, 18, (17,)),
    (17, 20, (20, 18)),  # 20점 칸
    (18, 22, (19,)),
    (19, 24, (9,)),
    (20, 22, (21,)),
    (21, 24, (22,)),
    (22, 26, (23,)),
    (23, 28, (24,)),
    (24, 30, (28, 25)),  # 30점 칸
    (25, 28, (26,)),
    (26, 27, (27,)),
    (27, 26, (9,)),
    (28, 32, (29,)),
    (29, 34, (30,)),
    (30, 36, (31,)),
    (31, 38, (12,)),
    (32, 0, (32,)) # 도착
)
state = [0,0,0,0]   # 말들의 현재 인덱스

### logic
def answer(state):
    max_score = 0
    q = deque()
    q.append((state, 0, 0))        # 상태, 여태 얻은 점수, 주사위 굴린 횟수
    while q:
        cur, score, cnt = q.popleft()
        if cnt == 10:   break
        
        for idx in range(4):
            if cur[idx] == 32:   break  # 도착 칸에 있는 말은 X
            next_state, gain = move(cur[:], idx, nums[cnt])
            if gain == -1:  continue    # 이동을 마치는 칸에 이미 말이 있는 경우
            q.append((next_state, score + gain, cnt+1))
            max_score = max(max_score, score + gain)
    return max_score

def move(state, idx, n):    # 현재 state에서 idx번째에 있는 말 하나를 n칸 옮긴 후의 state와 얻은 점수 반환
    horse_loc = state[idx]
    if horse_loc == 5 or horse_loc == 17 or horse_loc == 24:    # 파란칸에서 시작할때
        horse_loc = board[horse_loc][NEXTS][1]
        n -= 1
        
    while n > 0:
        if horse_loc == 32: break
        horse_loc = board[horse_loc][NEXTS][0]
        n -= 1    
    
    if horse_loc != 32 and horse_loc in state:
        return [], -1   # 이동을 마친 칸에 이미 말이 있는 경우
    
    state[idx] = horse_loc
    return state, board[horse_loc][SCORE]

### output
print(answer(state))