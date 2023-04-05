import sys; input = lambda:sys.stdin.readline().rstrip()

def roll_dice(dir, board, dice, x, y):
    if dir == 1:    # 동
        if y + 1 >= m:  return x, y
        y += 1
        dice[1],dice[2],dice[3],dice[5] = dice[5],dice[1],dice[2],dice[3]
        
    elif dir == 2:  # 서
        if y - 1 < 0:  return x, y
        y -= 1
        dice[1],dice[2],dice[3],dice[5] = dice[2],dice[3],dice[5],dice[1]
        
    elif dir == 3:  # 북
        if x - 1 < 0:  return x, y
        x -= 1
        dice[0],dice[2],dice[4],dice[5] = dice[2],dice[4],dice[5],dice[0]
        
    elif dir == 4:  # 남
        if x + 1 >= n:  return x, y
        x += 1
        dice[0],dice[2],dice[4],dice[5] = dice[5],dice[0],dice[2],dice[4]
        
    if board[x][y] == 0:
        board[x][y] = dice[5]
    else:
        dice[5] = board[x][y]
        board[x][y] = 0
        
    print(dice[2])
    return x, y

n, m, x, y, k = map(int,input().split())
board = [list(map(int,input().split())) for _ in range(n)]
commands = list(map(int,input().split()))
dice = [0,0,0,0,0,0]  # dice[2]:윗면, dice[5]:바닥면

for dir in commands:
    x, y = roll_dice(dir, board, dice, x, y)