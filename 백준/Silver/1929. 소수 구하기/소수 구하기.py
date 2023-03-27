import sys; input = lambda : sys.stdin.readline().rstrip()
import math

n, m = map(int,input().split())
arr = [True for _ in range(m+1)]
arr[1] = False

for i in range(2,int(math.sqrt(m))+1):
    if arr[i] == False:  continue
    for j in range(2*i, m+1, i):
        arr[j] = False
            
for i in range(n,m+1):
    if arr[i] == True:
        print(i)