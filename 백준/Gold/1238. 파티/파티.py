import heapq
import math

DES = 0
COST = 1

def dijkstra(start, end):   # start 에서 end까지 가는데 최소 소요시간을 반환
    cost_lst = [math.inf]*(n+1)  # start 에서 각 마을까지 가는 최단 시간
    visited = [False]*(n+1)
    hq = []
    
    cost_lst[start] = 0
    heapq.heappush(hq, (0, start))
    
    while hq:
        cost, cur = heapq.heappop(hq)
        if cur == end:  break
        if visited[cur]:    continue
        visited[cur] = True
        for road in all_roads[cur]:
            temp = cost+road[COST]
            if cost_lst[road[DES]] > temp:
                cost_lst[road[DES]] = temp
                heapq.heappush(hq, (temp, road[DES]))
    return cost_lst[end]

### input
n, m, x = map(int,input().split())
all_roads = [[] for _ in range(n+1)]    # i에서 갈수있는 [마을, 소요시간]의 리스트

### initialize
for _ in range(m):
    s, e, t = map(int,input().split())  # 시작점, 끝점, 소요시간
    all_roads[s].append([e,t])
# print(*all_roads, sep="\n")

### logic
max_time = 0
for i in range(1,n+1):
    time = dijkstra(i,x) + dijkstra(x,i)
    if max_time < time:
        max_time = time

### output
print(max_time)