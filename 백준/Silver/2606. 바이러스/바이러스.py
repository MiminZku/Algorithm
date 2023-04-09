from collections import deque

n = int(input())

links = [[] for _ in range(n+1)]
visited = [False]*(n+1)
p = int(input())

for _ in range(p):
    a, b = map(int,input().split())
    links[a].append(b)
    links[b].append(a)

q = deque([1])
visited[1] = True
count = 0
while q:
    cur = q.popleft()
    for com in links[cur]:
        if visited[com]:    continue
        q.append(com)
        visited[com] = True
        count += 1
print(count)