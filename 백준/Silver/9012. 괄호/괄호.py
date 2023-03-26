import sys; input = lambda:sys.stdin.readline().rstrip()

t = int(input())
for _ in range(t):
    stack = 0
    is_wrong = False
    string = input()
    for c in string:
        if c == '(':
            stack += 1
        else:
            stack -= 1
        if stack < 0:
            break
    if stack == 0:
        print("YES")
    else:
        print("NO")