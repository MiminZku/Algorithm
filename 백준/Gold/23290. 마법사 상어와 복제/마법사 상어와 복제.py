import sys; input = lambda : sys.stdin.readline().rstrip()
import copy;

def duplicate(f_mat, s_mat):
    global sr, sc
    # 1 복제 마법 시전
    org = copy.deepcopy(f_mat)
    # print_mat(org)
    # 2 물고기 이동
    new_f_mat = [ [ [] for _ in range(5) ] for _ in range(5)]
    for row in range(1,5):
        for col in range(1,5):
            for fish in f_mat[row][col]:
                next_r, next_c = row, col
                for i in range(8):
                    if fish == 1:                   next_c -= 1
                    elif fish == 2: next_r -= 1;    next_c -= 1    
                    elif fish == 3: next_r -= 1
                    elif fish == 4: next_r -= 1;    next_c += 1    
                    elif fish == 5:                 next_c += 1
                    elif fish == 6: next_r += 1;    next_c += 1    
                    elif fish == 7: next_r += 1
                    elif fish == 8: next_r += 1;    next_c -= 1
                    
                    if (next_c < 1 or 4 < next_c
                        or next_r < 1 or 4 < next_r
                        or next_r == sr and next_c == sc
                        or s_mat[next_r][next_c] > 0):
                        next_r, next_c = row, col
                        if fish == 1:   fish = 8
                        else:   fish -= 1
                    else:
                        break          
                new_f_mat[next_r][next_c].append(fish)
    # print_mat(new_f_mat)
    
    # 3 상어 3칸 이동
    f_num = [ [ 0 for _ in range(5) ] for _ in range(5)]
    for i in range(1,5):
        for j in range(1,5):
            f_num[i][j] = len(new_f_mat[i][j])
            
    max = -1; res = []
    for a in range(1,5):
        for b in range(1,5):
            for c in range(1,5):
                temp_mat = copy.deepcopy(f_num)
                dirs = [a,b,c]
                nagari = False
                sum = 0
                temp = []
                next_sr = sr; next_sc = sc
                for i in dirs:
                    if i == 1:      next_sr -= 1
                    elif i == 2:                    next_sc -= 1
                    elif i == 3:    next_sr += 1
                    elif i == 4:                    next_sc += 1
                    
                    if(next_sr < 1 or 4 < next_sr
                       or next_sc < 1 or 4 < next_sc):
                        nagari = True
                        break
                    
                    sum += temp_mat[next_sr][next_sc]
                    temp_mat[next_sr][next_sc] = 0
                    temp.append((next_sr,next_sc))
                if nagari:  continue
                if sum > max:
                    max = sum
                    res = temp
    # print(res)
    for row, col in res:
        if new_f_mat[row][col]:
            new_f_mat[row][col] = []
            s_mat[row][col] = 3
    sr = res[2][0]; sc = res[2][1]
    # print_mat(new_f_mat)
    # 4 냄새 옅어짐
    for i in range(1,5):
        for j in range(1,5):
            if s_mat[i][j] > 0: s_mat[i][j] -= 1
    # print_mat(s_mat)
    # 5 복제 마법 완성
    temp = [ [ [] for _ in range(5) ] for _ in range(5)]
    for i in range(1,5):
        for j in range(1,5):
            for fish in new_f_mat[i][j]:
                temp[i][j].append(fish)
            for fish in org[i][j]:
                temp[i][j].append(fish)
    # print_mat(temp)
    # print("-------------------------")
    return temp

# def print_mat(mat):
#     for i in range(1,5):
#         for j in range(1,5):
#             print(mat[i][j],end=" ")
#         print()
#     print("-------------------------")

f_mat = [ [ [] for _ in range(5) ] for _ in range(5)]
s_mat = [ [ 0 for _ in range(5)] for _ in range(5)]
m, s = map(int, input().split())
for _ in range(m):
    r, c, d = map(int,input().split())
    f_mat[r][c].append(d)
sr, sc = map(int,input().split())

for _ in range(s):
    f_mat = duplicate(f_mat, s_mat)

sum = 0
for i in f_mat:
    for j in i:
        sum += len(j)
print(sum)
