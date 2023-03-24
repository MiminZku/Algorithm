import copy

def simulate(board, direction, max_block, count):
    if count == 5:
        return max_block
    new_board = copy.deepcopy(swipe_board(board, direction))
    # print(count)
    # print_board(new_board)
    new_max = find_max(new_board)
    if new_max > max_block:
        max_block = new_max
    for i in range(4):
        new_max = simulate(copy.deepcopy(new_board), i, max_block, count+1)
        if new_max > max_block:
            max_block = new_max
    return max_block

def swipe_board(board, direction):
    board_len = len(board)
    if direction == 0:  # 위쪽
        for col in range(board_len):
            for row in range(1, board_len):
                if board[row][col][0] == 0:
                    continue
                i = row - 1
                while board[i][col][0] == 0 and i > 0:
                    i -= 1
                if board[i][col][0] == 0:  # 첫번재 행이 비어있을 경우
                    board[i][col][0] = board[row][col][0]
                    board[row][col][0] = 0
                elif (board[i][col][0] == board[row][col][0] 
                      and board[i][col][1] == 0): # 같아서 합쳐지는 경우
                    board[i][col][0] += board[row][col][0]
                    board[i][col][1] = 1
                    board[row][col][0] = 0
                else:   # 달라서 합쳐지지 않는 경우
                    board[i+1][col][0] = board[row][col][0]
                    if i+1 != row:
                        board[row][col][0] = 0

    elif direction == 1: # 왼쪽
        for row in range(board_len):
            for col in range(1, board_len):
                if board[row][col][0] == 0:
                    continue
                i = col - 1
                while board[row][i][0] == 0 and i > 0: 
                    i -= 1
                if board[row][i][0] == 0:  # 첫번재 열이 비어있을 경우
                    board[row][i][0]= board[row][col][0]
                    board[row][col][0] = 0
                elif (board[row][i][0] == board[row][col][0]
                      and board[row][i][1] == 0):  # 같아서 합쳐지는 경우
                    board[row][i][0] += board[row][col][0]
                    board[row][i][1] = 1
                    board[row][col][0] = 0
                else:   # 달라서 합쳐지지 않는 경우
                    board[row][i+1][0] = board[row][col][0]
                    if i+1 != col:
                        board[row][col][0] = 0

    elif direction == 2: # 아래쪽
        for col in range(board_len):
            for row in range(board_len-2, -1, -1):
                if board[row][col][0] == 0:
                    continue
                i = row + 1
                while board[i][col][0] == 0 and i < board_len - 1:
                    i += 1
                if board[i][col][0] == 0:  # 마지막 행이 비어있을 경우
                    board[i][col][0] = board[row][col][0]
                    board[row][col][0] = 0
                elif (board[i][col][0] == board[row][col][0]
                      and board[i][col][1] == 0):  # 같아서 합쳐지는 경우
                    board[i][col][0] += board[row][col][0]
                    board[i][col][1] = 1
                    board[row][col][0] = 0
                else:   # 달라서 합쳐지지 않는 경우
                    board[i-1][col][0] = board[row][col][0]
                    if i-1 != row:
                        board[row][col][0] = 0
    
    elif direction == 3: # 오른쪽
        for row in range(board_len):
            for col in range(board_len-2, -1, -1):
                if board[row][col][0] == 0:
                    continue
                i = col + 1
                while board[row][i][0] == 0 and i < board_len - 1: 
                    i += 1
                if board[row][i][0] == 0:  # 마지막 열이 비어있을 경우
                    board[row][i][0] = board[row][col][0]
                    board[row][col][0] = 0
                elif (board[row][i][0] == board[row][col][0]
                      and board[row][i][1] == 0):  # 같아서 합쳐지는 경우
                    board[row][i][0] += board[row][col][0]
                    board[row][i][1] = 1
                    board[row][col][0] = 0
                else:   # 달라서 합쳐지지 않는 경우
                    board[row][i-1][0] = board[row][col][0]
                    if i-1 != col:
                        board[row][col][0] = 0
    clear_board(board)
    return board

def print_board(board):
    print()
    for i in board:
        for j in i:
            print("%4d" %(j[0]),end=" ")
        print()

def find_max(board):
    max = 0
    for i in board:
        for j in i:
            if max < j[0]:
                max = j[0]
    return max

def clear_board(board):
    for i in board:
        for j in i:
            j[1] = 0

if __name__ == "__main__":
    n = int(input())
    board = []
    for i in range(n):
        temp = [[0, 0] for _ in range(n)]   # 0번 인덱스는 숫자, 1번 인덱스는 이미 합쳐졌는지
        row_input = list(map(int, input().split()))
        for j in range(n):
            temp[j][0] = row_input[j]
        board.append(temp)
    
    max_block = find_max(board)
    for i in range(4):
        new_max = simulate(copy.deepcopy(board), i, max_block, 0)
        if new_max > max_block:
            max_block = new_max
    print(max_block)