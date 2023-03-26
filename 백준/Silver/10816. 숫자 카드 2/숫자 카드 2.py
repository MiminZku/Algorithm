import sys; input = lambda:sys.stdin.readline().rstrip()

n = int(input())
cards = list(map(int,input().split()))
m = int(input())
nums = list(map(int,input().split()))

count = dict()
for i in cards:
    count[i] = count.get(i,0)+1
for i in nums:
    print(count.get(i,0),end=" ")