def init(fish_bowl):
    minimum = min(map(min,fish_bowl))
    for i in range(n):
        if fish_bowl[i][0] == minimum:
            fish_bowl[i][0] += 1
    return fish_bowl

def stack(fish_bowl):
    i = 0
    while True:
        idx = int(i//1)
        temp = fish_bowl[0:idx+1]
        tail = fish_bowl[idx+1:] if idx+1 < len(fish_bowl) else []
        if len(temp[0]) > len(tail):
            return fish_bowl
        else:
            fish_bowl = tail

        for row in range(len(temp)-1,-1,-1):
            for col in range(len(temp[0])):
                fish_bowl[col].append(temp[row][col])
        i += 0.5

def control(fish_bowl):
    row_len = len(fish_bowl)
    col_len = len(fish_bowl[0])
    for row in range(row_len):
        if len(fish_bowl[row]) < col_len:
            fish_bowl[row] += [-1]*(col_len-1)
    temp = [ [ 0 for _ in range(col_len)] for _ in range(row_len)]
    navers = [(0,1),(0,-1),(-1,0),(1,0)] 
    for row in range(len(fish_bowl)):
        for col in range(len(fish_bowl[row])):
            for r, c in navers:
                n_row = row+r; n_col = col+c
                if n_row < 0 or n_row >= row_len \
                or n_col < 0 or n_col >= col_len \
                or fish_bowl[n_row][n_col] == -1 \
                or fish_bowl[n_row][n_col] > fish_bowl[row][col]:
                    continue
                delta = fish_bowl[row][col] - fish_bowl[n_row][n_col]
                d = delta // 5
                temp[row][col] -= d
                temp[n_row][n_col] += d
    return add_mat(fish_bowl,temp,row_len,col_len)

def flatten(fish_bowl):
    res = []
    for row in fish_bowl:
        for col in row:
            if col >= 0:
                res.append([col])
    return res

def stack2(fish_bowl):
    for i in range(2):
        mid = len(fish_bowl)//2
        temp = fish_bowl[0:mid]
        fish_bowl = fish_bowl[mid:]
        for col in range(i,-1,-1):
            j = 0
            for row in range(mid-1,-1,-1):
                fish_bowl[j].append(temp[row][col])
                j += 1
    return fish_bowl

def add_mat(X,Y,r,c):
    return [[ (X[i][j] + Y[i][j])  for j in range(c)] for i in range(r)]

### input
n, k = map(int, input().split())
fish_bowl = list(map(int, input().rstrip().split()))
for i in range(n):
    fish_bowl[i] = [fish_bowl[i]]
count = 0

### logic
while max(map(max,fish_bowl)) - min(map(min,fish_bowl)) > k:
    count += 1
    fish_bowl = init(fish_bowl)
    fish_bowl = stack(fish_bowl)
    fish_bowl = control(fish_bowl)
    fish_bowl = flatten(fish_bowl)
    fish_bowl = stack2(fish_bowl)
    fish_bowl = control(fish_bowl)
    fish_bowl = flatten(fish_bowl)
    # print(fish_bowl)

### output
print(count)