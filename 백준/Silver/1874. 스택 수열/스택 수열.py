import sys; input = lambda: sys.stdin.readline().rstrip()
from collections import deque

n = int(input())
arr = [int(input()) for _ in range(n)]
stack = deque()
ans = []
next = 1

for idx in range(arr[0]-1):
    stack.append(next)
    ans.append('+')
    next += 1

idx = 0
while idx < n:
    if arr[idx] not in stack and arr[idx] < next:
        print('NO')
        exit()
    
    if arr[idx] < next:
        top = stack.pop()
        ans.append('-')
        if arr[idx] == top:
            idx += 1
    elif arr[idx] > next:
        stack.append(next)
        ans.append('+')
        next += 1
    else:
        ans.append('+')
        ans.append('-')
        next += 1
        idx += 1
        
print(*ans,sep="\n")