from collections import deque

n = int(input())
q = deque()
for i in range(n):
    q.append(i+1)
    
while n > 1:
    q.popleft()
    q.append(q.popleft())
    n -= 1
print(q.popleft())