import sys; input = lambda: sys.stdin.readline().rstrip()

def dfs(consultings, start, end):
    if start > end: return 0
    if consultings[start-1][0]+start > end + 1:
        return dfs(consultings, start+1, end)
    a = dfs(consultings, start+1, end)
    b = consultings[start-1][1] + dfs(consultings,start+consultings[start-1][0],end)
    
    return a if a>b else b

n = int(input())
consultings = [list(map(int,input().split())) for _ in range(n)]

print(dfs(consultings, 1,n))