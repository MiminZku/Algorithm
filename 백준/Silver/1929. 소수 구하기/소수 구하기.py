import sys; input = lambda : sys.stdin.readline().rstrip()
import math

n, m = map(int,input().split())
arr = [True] * (m+1)
arr[1] = False

end = int(math.sqrt(m))
for i in range(2,end+1):
    if arr[i] == True:
        for j in range(2*i, m+1, i):
            arr[j] = False
            
for i in range(n,m+1):
    if arr[i] == True:
        print(i)