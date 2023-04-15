import sys; input=lambda: sys.stdin.readline()

n = int(input())
lst = list(map(int, input().rstrip().split()))
group = [[0 for _ in range(n)] for _ in range(n)]  #group[i][j] = lst[i:j+1]의 결과값

for i in range(n-1,-1,-1):
    for j in range(i+1, n):
        temp = lst[i:j+1]        
        max_delta = max(temp)-min(temp)
        for p in range(0, j-i):
            max_delta = max(max_delta, group[i][i+p] + group[i+p+1][j])
        group[i][j] = max_delta

print(group[0][n-1])