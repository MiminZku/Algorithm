import sys

lst = [0 for _ in range(10001)]
n = int(sys.stdin.readline())
for _ in range(n):
    i = int(sys.stdin.readline())
    lst[i] += 1
for i in range(10001):
    if lst[i]==0:    continue
    for _ in range(lst[i]):
        print(i)