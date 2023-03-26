t = int(input())
for _ in range(t):
    h, w, n = map(int,input().split())
    yy = 0; xx = 1
    for _ in range(n):
        yy += 1
        if yy > h:
            yy = 1
            xx += 1
    print("%d%02d" % (yy,xx))