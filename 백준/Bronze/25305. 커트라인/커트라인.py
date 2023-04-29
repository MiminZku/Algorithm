n, k = map(int,input().split())
scores = list(map(int, input().rstrip().split()))

scores.sort()
print(scores[n-k])