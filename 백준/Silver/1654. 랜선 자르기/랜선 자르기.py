def check(m):
    if sum(l//m for l in lens) >= n:
        return True
    else:
        return False

k, n = map(int,input().split())
lens = [int(input()) for _ in range(k)]
max_len = max(lens)

lo = 0; hi = max_len+1
while lo + 1 != hi:
    mid = (lo+hi)//2
    if check(mid):
        lo = mid
    else:
        hi = mid
print(lo)