import sys; input = lambda : sys.stdin.readline().rstrip()

def check(a):
    s = 0
    for h in h_list:
        if h <= a:   continue
        s += h - a
    if s >= m:  return True
    return False

def bin_search():
    lo = 0 ; hi = h_list[-1]
    while lo+1 != hi:
        mid = (lo+hi)//2
        if check(mid):
            lo = mid
        else:
            hi = mid
    return lo
    
n, m = map(int,input().split())
h_list = list(map(int,input().split()))
h_list.sort()

print(bin_search())