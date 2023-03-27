import sys; input = lambda : sys.stdin.readline().rstrip()

def is_prime(n):
    if n == 1:  return False
    if n>2 and n % 2 == 0:  return False
    for i in range(3,int(n**(0.5))+1,2):
        if n % i == 0:
            return False
    return True

n, m = map(int,input().split())
for i in range(n, m+1):
    if is_prime(i):
        print(i)