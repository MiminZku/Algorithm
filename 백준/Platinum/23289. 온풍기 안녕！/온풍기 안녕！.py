def wind(room, walls, heaters):
    for heater in heaters:
        temp_mat = [[0 for _ in range(c)] for _ in range(r)]
        temp = 5
        if heater[2] == 1:      # 오른쪽
            temp_mat[heater[0]][heater[1]+1] = temp
            for col in range(heater[1]+1, c-1):
                temp -= 1
                if temp == 0:   break
                for row in range(r):
                    if temp_mat[row][col] == 0: continue
                    
                    if ( row-1 >= 0 and 
                        (row,col) not in walls.get((row-1,col),[]) and
                        (row-1,col) not in walls.get((row-1,col+1),[])):
                        temp_mat[row-1][col+1] = temp

                    if ( (row,col) not in walls.get((row,col+1),[])):
                        temp_mat[row][col+1] = temp

                    if ( row+1 < r and
                         (row,col) not in walls.get((row+1,col),[]) and
                         (row+1,col) not in walls.get((row+1,col+1),[])):
                        temp_mat[row+1][col+1] = temp

        elif heater[2] == 2:    # 왼쪽
            temp_mat[heater[0]][heater[1]-1] = temp
            for col in range(heater[1]-1, 0, -1):
                temp -= 1
                if temp == 0:   break
                for row in range(r):
                    if temp_mat[row][col] == 0: continue
                    
                    if ( row-1 >= 0 and 
                        (row,col) not in walls.get((row-1,col),[]) and
                        (row-1,col) not in walls.get((row-1,col-1),[])):
                        temp_mat[row-1][col-1] = temp

                    if ( (row,col) not in walls.get((row,col-1),[])):
                        temp_mat[row][col-1] = temp

                    if ( row+1 < r and
                         (row,col) not in walls.get((row+1,col),[]) and
                         (row+1,col) not in walls.get((row+1,col-1),[])):
                        temp_mat[row+1][col-1] = temp

        elif heater[2] == 3:    # 위
            temp_mat[heater[0]-1][heater[1]] = temp
            for row in range(heater[0]-1, 0, -1):
                temp -= 1
                if temp == 0:   break
                for col in range(c):
                    if temp_mat[row][col] == 0: continue
                    
                    if ( col-1 >= 0 and 
                        (row,col) not in walls.get((row,col-1),[]) and
                        (row,col-1) not in walls.get((row-1,col-1),[])):
                        temp_mat[row-1][col-1] = temp

                    if ( (row,col) not in walls.get((row-1,col),[])):
                        temp_mat[row-1][col] = temp

                    if ( col+1 < c and
                         (row,col) not in walls.get((row,col+1),[]) and
                         (row,col+1) not in walls.get((row-1,col+1),[])):
                        temp_mat[row-1][col+1] = temp

        elif heater[2] == 4:    # 아래
            temp_mat[heater[0]+1][heater[1]] = temp
            for row in range(heater[0]+1, r-1):
                temp -= 1
                if temp == 0:   break
                for col in range(c):
                    if temp_mat[row][col] == 0: continue
                    
                    if ( col-1 >= 0 and 
                        (row,col) not in walls.get((row,col-1),[]) and
                        (row,col-1) not in walls.get((row+1,col-1),[])):
                        temp_mat[row+1][col-1] = temp

                    if ( (row,col) not in walls.get((row+1,col),[])):
                        temp_mat[row+1][col] = temp

                    if ( col+1 < c and
                         (row,col) not in walls.get((row,col+1),[]) and
                         (row,col+1) not in walls.get((row+1,col+1),[])):
                        temp_mat[row+1][col+1] = temp
        room = add_mat(room,temp_mat)
    return room
        
def controlled(room, walls):
    temp_mat = [[0 for _ in range(c)] for _ in range(r)]
    navers = [(0,1),(0,-1),(-1,0),(1,0)]
    for i in range(r):
        for j in range(c):
            if room[i][j] == 0: continue
            cant_go = walls.get((i,j),[])
            for row, col in navers:
                row += i; col += j
                if row<0 or row>=r or col<0 or col>=c:  continue
                if (row,col) in cant_go:    continue
                if room[i][j] <= room[row][col]:    continue
                delta = room[i][j] - room[row][col]
                temp_mat[i][j] -= delta//4
                temp_mat[row][col] += delta//4
    return  add_mat(room,temp_mat)

def cool_border(room):
    for i in range(r):
        for j in range(c):
            if i == 0 or i == r-1 or j == 0 or j == c-1:
                if room[i][j] > 0:
                    room[i][j] -= 1

def check(room, check_list):
    for r, c in check_list:
        if room[r][c] < k: return False
    return True

def add_mat(X,Y):
    return [[ (X[i][j] + Y[i][j])  for j in range(c)] for i in range(r)]

### input
r,c,k = map(int,input().split())
room_temp = [list(map(int,input().rstrip().split())) for _ in range(r)]
w = int(input())
walls_temp = [list(map(int,input().rstrip().split())) for _ in range(w)]

### initialize
chocolate = 0
room = [[0 for _ in range(c)] for _ in range(r)]    # 방의 온도 정보
heaters = []        # (행,열,방향) 으로 온풍기 정보 저장
check_list = []     # (행,열) 으로 조사해야 하는 칸 정보 저장
for row in range(r):
    for col in range(c):
        if room_temp[row][col] == 0:    continue
        elif room_temp[row][col] < 5:
            heaters.append((row,col,room_temp[row][col]))
        else:
            check_list.append((row,col))
walls = dict()      # (행,열) : [(행,열), ...]
for wall in walls_temp:
    a = (wall[0]-1,wall[1]-1)
    b = (wall[0]-2,wall[1]-1) if wall[2] == 0 else (wall[0]-1,wall[1])
    walls[a] = walls.get(a, []) + [b]
    walls[b] = walls.get(b, []) + [a]

### logic
while True:
    room = wind(room, walls, heaters)
    room = controlled(room, walls)
    cool_border(room)
    chocolate += 1
    # print(*room,sep="\n")
    if check(room, check_list) or chocolate > 100: break

### output
print(chocolate)