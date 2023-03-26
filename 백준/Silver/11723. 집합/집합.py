import sys; input = lambda:sys.stdin.readline().rstrip()

all_set = [1 for _ in range(21)]
zero_set = [0 for _ in range(21)]
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
        sys.stdout.write(str(s[n])+'\n')
    elif args[0] == 'toggle':
        s[n] = 0 if s[n] == 1 else 1
    elif args[0] == 'all':
        s = all_set
    elif args[0] == 'empty':
        s = zero_set        
    else:
        print("wrong command")