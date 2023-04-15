import sys; input = lambda : sys.stdin.readline()

### init
n = int(input())
mat = [tuple(map(int,input().rstrip().split())) for _ in range(n)]
dp = [[2**31 for _ in range(n)] for _ in range(n)] 
# dp[i][j] = i번재부터 j번째까지의 행렬들을 곱하는데 필요한 최소 연산 횟수

### logic
def num_of_mul(a, b):
    return a[0]*b[0]*b[1]

def mul(a, b):
    return (a[0], b[1])
     
for i in range(n-1,-1,-1):
    for j in range(i,n):
        if i==j:    dp[i][j] = 0;   continue
        
        res = 2**31
        for p in range(j-i):
            temp = dp[i][i+p] + dp[i+p+1][j] + \
                    num_of_mul(mul(mat[i],mat[i+p]), mul(mat[i+p+1], mat[j]))
            res = min(res, temp)
        dp[i][j] = res
        
### output
print(dp[0][n-1])