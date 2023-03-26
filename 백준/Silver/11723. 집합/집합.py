import sys; input = lambda:sys.stdin.readline().rstrip()

s = [0 for _ in range(21)]
m = int(input())
for _ in range(m):
    args = input().split()
    if len(args) > 1:
        n = int(args[1])
    if args[0] == 'add':
        s[n] = 1
    elif args[0] == 'remove':
        s[n] = 0
    elif args[0] == 'check':
        print(s[n])
    elif args[0] == 'toggle':
        s[n] = 0 if s[n] == 1 else 1
    elif args[0] == 'all':
        s = [1 for _ in range(21)]
    elif args[0] == 'empty':
        s = [0 for _ in range(21)]        
    else:
        print("wrong command")