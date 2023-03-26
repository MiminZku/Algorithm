import sys; input = lambda:sys.stdin.readline().rstrip()

n = int(input())
max = n//5
for i in range(max,-1,-1):
    rest = n if i==0 else n-(i*5)
    bongji_5 = 0 if i==0 else i
    bongji_3 = rest//3
    if bongji_5*5 + bongji_3*3 == n:
        print(bongji_3+bongji_5)
        exit()
print(-1)