import sys; input = lambda : sys.stdin.readline().rstrip()

n = int(input())
cost = [list(map(int,input().split())) for _ in range(n)]
res = []

memo = [cost[0]]
for i in range(1,n):    # 1번 집이 R일때
    temp = []
    if i == 1:
        temp.append(1_000_000)
        temp.append(memo[i-1][0] + cost[i][1])
        temp.append(memo[i-1][0] + cost[i][2])
        memo.append(temp)
        continue
    if i == n-1:
        temp.append(min(memo[i-1][0],memo[i-1][2]) + cost[i][1])
        temp.append(min(memo[i-1][0],memo[i-1][1]) + cost[i][2])
        memo.append(temp)
        break
    temp.append(min(memo[i-1][1],memo[i-1][2]) + cost[i][0])
    temp.append(min(memo[i-1][0],memo[i-1][2]) + cost[i][1])
    temp.append(min(memo[i-1][0],memo[i-1][1]) + cost[i][2])
    memo.append(temp)
res.append(min(memo[-1]))

memo = [cost[0]]
for i in range(1,n):    # 1번 집이 G일때
    temp = []
    if i == 1:
        temp.append(memo[i-1][1] + cost[i][0])
        temp.append(1_000_000)
        temp.append(memo[i-1][1] + cost[i][2])
        memo.append(temp)
        continue
    if i == n-1:
        temp.append(min(memo[i-1][1],memo[i-1][2]) + cost[i][0])
        temp.append(min(memo[i-1][0],memo[i-1][1]) + cost[i][2])
        memo.append(temp)
        break
    temp.append(min(memo[i-1][1],memo[i-1][2]) + cost[i][0])
    temp.append(min(memo[i-1][0],memo[i-1][2]) + cost[i][1])
    temp.append(min(memo[i-1][0],memo[i-1][1]) + cost[i][2])
    memo.append(temp)
res.append(min(memo[-1]))

memo = [cost[0]]
for i in range(1,n):    # 1번 집이 B일때
    temp = []
    if i == 1:
        temp.append(memo[i-1][2] + cost[i][0])
        temp.append(memo[i-1][2] + cost[i][1])
        temp.append(1_000_000)
        memo.append(temp)
        continue
    if i == n-1:
        temp.append(min(memo[i-1][1],memo[i-1][2]) + cost[i][0])
        temp.append(min(memo[i-1][0],memo[i-1][2]) + cost[i][1])
        memo.append(temp)
        break
    temp.append(min(memo[i-1][1],memo[i-1][2]) + cost[i][0])
    temp.append(min(memo[i-1][0],memo[i-1][2]) + cost[i][1])
    temp.append(min(memo[i-1][0],memo[i-1][1]) + cost[i][2])
    memo.append(temp)
res.append(min(memo[-1]))

print(min(res))