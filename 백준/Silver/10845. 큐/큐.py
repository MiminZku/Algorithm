import sys; input = lambda:sys.stdin.readline().rstrip()
from collections import deque

q = deque()
n = int(input())
for _ in range(n):
    args = input().split()
    if args[0] == 'push':
        q.appendleft(int(args[1]))
    elif args[0] == 'pop':
        if len(q) == 0:
            print(-1)
        else:
            print(q.pop())
    elif args[0] == 'size':
        print(len(q))
    elif args[0] == 'empty':
        if len(q) == 0:
            print(1)
        else:
            print(0)
    elif args[0] == 'front':
        if len(q) == 0:
            print(-1)
        else:
            print(q[len(q)-1])
    elif args[0] == 'back':
        if len(q) == 0:
            print(-1)
        else:
            print(q[0])
    else:
        print("wrong command")