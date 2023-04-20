import sys; input = lambda:sys.stdin.readline().rstrip()
from collections import deque

n, m = map(int,input().split())
little = dict()
for _ in range(m):
    v = int(input())
    little[v] = True
check = [[] for _ in range(n+1)]

q = deque()
q.append((1,1,0)) # 돌 번호, 현재 속도, 점프한 횟수
while q:
    cur_stone, cur_speed, jump_count = q.popleft()
    next = []
    if cur_speed == 1:
        if cur_stone == 1:  next = [2]
        else:   next = [cur_stone + cur_speed, cur_stone + cur_speed + 1]
    else:
        next = [cur_stone + cur_speed-1, cur_stone + cur_speed, cur_stone + cur_speed+1]
    
    for next_stone in next:
        if next_stone == n:
            print(jump_count+1)
            exit()            
        if next_stone > n or little.get(next_stone, False) or cur_speed in check[next_stone]:    continue
        check[next_stone].append(next_stone - cur_stone)
        q.append((next_stone, next_stone - cur_stone, jump_count + 1))
print(-1)