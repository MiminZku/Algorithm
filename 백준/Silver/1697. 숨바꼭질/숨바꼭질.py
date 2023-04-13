from collections import deque

def bfs():
    if n == k:  return 0
    visited = dict()
    visited[n] = 0
    q = deque()
    q.append(n)
    while q:
        cur = q.popleft()
        if cur == k:
            return visited[cur] 
        navers = [cur-1, cur+1, cur*2]
        for naver in navers:
            if naver < 0 or naver > 200000: continue
            if visited.get(naver, -1) >= 0:   continue
            q.append(naver)
            visited[naver] = visited[cur]+1

n, k = map(int,input().split())
print(bfs())