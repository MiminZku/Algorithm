import sys; input = lambda:sys.stdin.readline().rstrip()
import copy;
from collections import deque

def bfs(board):
    board_que = deque()
    board_que.appendleft([0,board])
    visited = [board]
    while len(board_que) != 0:
        u = board_que.pop()
        if u[0] >= 10:   return -1
        navers = []
        for dir in range(4):
            new_board = tilt_board(copy.deepcopy(u[1]),dir)
            navers.append(new_board)
            if is_game_clear(new_board):
                return u[0]+1
        for brd in navers:
            if brd not in visited:
                visited.append(brd)
                board_que.appendleft([u[0]+1,brd])
    return -1
        
def tilt_board(board, direction):
    row_len = len(board)
    col_len = len(board[0])
    idx_R = find_ball(board,'R')
    idx_B = find_ball(board,'B')
    if direction == 0:   # 위쪽으로 기울이기
        for col in range(1, col_len-1):
            for row in range(1, row_len-1):
                idx = [row,col]
                if idx != idx_R and idx != idx_B:   continue
                while board[idx[0]-1][idx[1]] == '.' and idx[0] > 1:
                    idx[0] -= 1
                if idx == [row,col]:
                    if board[row-1][col] == 'O':
                        board[row][col] = '.'
                    continue
                if board[idx[0]-1][idx[1]] != 'O':
                    board[idx[0]][idx[1]] = board[row][col]
                board[row][col] = '.'
    elif direction == 1: # 왼쪽으로 기울이기
        for row in range(1, row_len-1):
            for col in range(1, col_len-1):
                idx = [row,col]
                if idx != idx_R and idx != idx_B:   continue
                while board[idx[0]][idx[1]-1] == '.' and idx[1] > 1:
                    idx[1] -= 1
                if idx == [row,col]:
                    if board[row][col-1] == 'O':
                        board[row][col] = '.'
                    continue
                if board[idx[0]][idx[1]-1] != 'O':
                    board[idx[0]][idx[1]] = board[row][col]
                board[row][col] = '.'
    elif direction == 2: # 아래쪽으로 기울이기
        for col in range(1, col_len-1):
            for row in range(row_len-2, 0, -1):
                idx = [row,col]
                if idx != idx_R and idx != idx_B:   continue
                while board[idx[0]+1][idx[1]] == '.' and idx[0] < row_len-2:
                    idx[0] += 1
                if idx == [row,col]:
                    if board[row+1][col] == 'O':
                        board[row][col] = '.'
                    continue
                if board[idx[0]+1][idx[1]] != 'O':
                    board[idx[0]][idx[1]] = board[row][col]
                board[row][col] = '.'        
    elif direction == 3: # 오른쪽으로 기울이기
        for row in range(1, row_len-1):
            for col in range(col_len-2, 0, -1):
                idx = [row,col]
                if idx != idx_R and idx != idx_B:   continue
                while board[idx[0]][idx[1]+1] == '.' and idx[1] < col_len-2:
                    idx[1] += 1
                if idx == [row,col]:
                    if board[row][col+1] == 'O':
                        board[row][col] = '.'
                    continue
                if board[idx[0]][idx[1]+1] != 'O':
                    board[idx[0]][idx[1]] = board[row][col]
                board[row][col] = '.'
    return board

def find_ball(board, ball):
    for row in range(len(board)):
        for col in range(len(board[0])):
            if board[row][col] == ball:
                return [row,col]
    return[-1,-1]

def is_game_clear(board):
    idx_R = find_ball(board,'R')
    idx_B = find_ball(board,'B')
    if idx_R == [-1,-1] and idx_B != [-1,-1]:
        return True
    return False

if __name__ == "__main__":
    n, m = map(int, input().split())
    board = []
    for _ in range(n):
        row = list(input())
        board.append(row)
    print(bfs(copy.deepcopy(board)))