import sys; input = lambda:sys.stdin.readline().rstrip()
from collections import deque

dq = deque()
n = int(input())
for _ in range(n):
    args = input().split()
    if args[0] == 'push_front':
        dq.appendleft(int(args[1]))
    elif args[0] == 'push_back':
        dq.append(int(args[1]))
    elif args[0] == 'pop_front':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.popleft())
    elif args[0] == 'pop_back':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.pop())
    elif args[0] == 'size':
        print(len(dq))
    elif args[0] == 'empty':
        if len(dq) == 0:
            print(1)
        else:
            print(0)
    elif args[0] == 'front':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[0])
    elif args[0] == 'back':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[len(dq)-1])
    else:
        print("wrong command")