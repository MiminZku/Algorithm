t = int(input())
for _ in range(t):
    r, s = input().split()
    for c in s:
        for _ in range(int(r)):
            print(c,end='')
    print()