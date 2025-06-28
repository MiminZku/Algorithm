n, d = map(int, input().split())
cnt = [int(input()) for _ in range(n)]
div = sum(cnt)
for c in cnt:
    print(int(d * c / div), end = '\n')