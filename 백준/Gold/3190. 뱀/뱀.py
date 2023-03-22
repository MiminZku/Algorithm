def Main():
    N = int(input())
    board = [[0 for _ in range(N)] for _ in range(N)]
    board[0][0] = 1 # 1이 뱀의 몸
    
    K = int(input())
    for _ in range(K):
        row, col = input().split()
        row = int(row) ; col = int(col)
        board[row-1][col-1] = 2 # 2가 사과
    # PrintBoard(board)

    L = int(input())
    commandList = []
    for _ in range(L):
        X, C = input().split()
        X = int(X)
        temp = [X,C]
        commandList.append(temp)

    print(PlayGame(board,commandList))

def PlayGame(board, commandList):
    headIndex = [0,0]
    snake = [headIndex.copy()]
    time = 0; commandIndex = 0
    direction = 0   # 0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
    while(True):
        # PrintBoard(board)
        time += 1
        if direction == 0:
            headIndex[1] += 1            
        elif direction == 1:
            headIndex[0] += 1
        elif direction == 2:
            headIndex[1] -= 1        
        elif direction == 3:
            headIndex[0] -= 1
        
        if(IsGameOver(board,headIndex)):
            break

        if(board[headIndex[0]][headIndex[1]] == 2):
            board[headIndex[0]][headIndex[1]] = 1
            snake.insert(0,headIndex.copy())
        else:
            board[headIndex[0]][headIndex[1]] = 1
            snake.insert(0,headIndex.copy())
            board[snake[-1][0]][snake[-1][1]] = 0
            snake.pop()
        if(commandIndex != len(commandList) and 
           time == commandList[commandIndex][0]):
            if(commandList[commandIndex][1] == "D"):
                direction = (direction + 1) % 4
            else:
                direction = (direction + 3) % 4
            commandIndex += 1        
    return time

def IsGameOver(board,currentHeadIndex):
    if(currentHeadIndex[0] < 0 or currentHeadIndex[1] < 0 or
        currentHeadIndex[0] >= len(board) or currentHeadIndex[1] >= len(board) or
        board[currentHeadIndex[0]][currentHeadIndex[1]] == 1):
        return True
    return False

def PrintBoard(board):
    for i in range(len(board)):
        for j in range(len(board)):
            print(board[i][j], end = " ")
        print()
    print("-----------------------------------------")
    
if __name__ == '__main__':
    Main()