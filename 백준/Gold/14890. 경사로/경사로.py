def can_pass(road):
    slope = [False] * N
    pre = road[0]
    for i in range(1,N):
        if road[i] > pre:    # 높아졌을 때
            if road[i] - pre > 1: return False
            for j in range(1,L+1):
                if i - j < 0 \
                or road[i-j] != road[i]-1 \
                or slope[i-j]:
                    return False
                slope[i-j] = True
        elif road[i] < pre:  # 낮아졌을 때
            if pre - road[i] > 1: return False
            for j in range(0,L):
                if i + j >= N \
                or road[i+j] != road[i]:
                    return False
                slope[i+j] = True            
        pre = road[i]
    return True

N, L = map(int, input().split())
board = [list(map(int,input().rstrip().split())) for _ in range(N)]

result = 0

for r in range(N):
    row = board[r][:]
    if can_pass(row):
        result += 1

for c in range(N):
    col = [board[i][c] for i in range(N)]
    if can_pass(col):
        result += 1

print(result)