def blizard(line,d,s):
    for k in range(s,0,-1):
        index = 0
        if d == 1:      index = 4*k*k + 3*k
        elif d == 2:    index = 4*k*k - k
        elif d == 3:    index = 4*k*k - 3*k
        elif d == 4:    index = 4*k*k + k
        del line[index]
    while len(line) < length:
        line.append(0)

def explode(line):
    while True:
        pre = 0
        explode_count = 0
        count = 1
        i = 1
        while i < length:
            if line[i] != pre:
                if count > 3:
                    explode_count += 1
                    marvel_count[pre-1] += count
                    for j in range(count):
                        del line[i-1 -j]
                    while len(line) < length:
                        line.append(0)
                    pre = 0; i = i-count+1
                    count = 1
                    continue
                pre = line[i]
                count = 1
            else:
                count += 1
            i += 1
        if explode_count == 0:  break

def change(line):
    new_line = [0]
    pre = line[1]
    count = 1
    for i in range(2,length):
        if line[i] != pre:
            new_line += [count,pre]
            pre = line[i]
            count = 1
        else:
            count += 1
    while len(new_line) < length:
        new_line.append(0)
    return new_line[:length]        

### input
n, m = map(int, input().split())
length = n*n
board = [ list(map(int,input().split())) for _ in range(n)]
line = []
marvel_count = [0,0,0]
for i in range(n//2):
    for col in range(i, n-1 -i):
        line.append(board[i][col])
    for row in range(i, n-1 -i):
        line.append(board[row][n-1 - i])
    for col in range(n-1 -i , i , -1):
        line.append(board[n-1 -i][col])
    for row in range(n-1 -i , i , -1):
        line.append(board[row][i])
line.append(0)    
line.reverse()
# print(line)
commands = [list(map(int,input().split())) for _ in range(m)]

### logic
for com in commands:
    d, s = com[0],com[1]
    blizard(line,d,s)
    explode(line)
    line = change(line)
    # print(line)
print(marvel_count[0] + 2*marvel_count[1] + 3*marvel_count[2])