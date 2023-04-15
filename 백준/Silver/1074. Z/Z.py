def row(r):
    if r == 0:      return 0
    elif r == 1:    return 2
    e = 0
    while r >= 2**e:
        e += 1
    e -= 1
    return row(r - 2**e) + 2**(e*2+1)

def col(c):
    if c == 0:      return 0
    elif c == 1:    return 1
    e = 0
    while c >= 2**e:
        e += 1
    e -= 1
    return col(c - 2**e) + 2**(e*2)
    
n,r,c = map(int,input().split())
print(row(r)+col(c))