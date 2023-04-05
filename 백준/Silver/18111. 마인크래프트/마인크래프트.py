import sys; input = lambda: sys.stdin.readline()

def flat(ground, h, b):
    higher = 0
    lower = 0
    for i in ground:
        for j in i:
            if j == h: continue
            elif j > h:
                higher += j - h
            else:
                lower += h - j
    if higher + b < lower:
        return -1
    else:
        return 2*higher + lower

n, m, b = map(int,input().split())
ground = [list(map(int,input().split())) for _ in range(n)]
top = max(map(max, ground))
bot = min(map(min, ground))

min_t = 1_000_000_000
max_h = bot
for h in range(bot, top+1):
    cur_t = flat(ground, h, b)
    if cur_t != -1 and cur_t <= min_t:
        min_t = cur_t
        max_h = h
print(min_t,max_h)