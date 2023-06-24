import sys; input = lambda:sys.stdin.readline().rstrip()

n, m = map(int,input().split())
dic = dict()
for _ in range(n):
    dic[input()] = 0
for _ in range(m):
    name = input()
    dic[name] = 1 if name in dic else 0

res = [k for k, v in dic.items() if v == 1]
print(len(res))
print(*sorted(res),sep="\n")