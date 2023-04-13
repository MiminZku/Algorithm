n = int(input())
stairs = [int(input()) for _ in range(n)]
if n == 1:
    print(stairs[0])
    exit()
max_score = [
    [stairs[0], stairs[0]],
    [stairs[1], stairs[0] + stairs[1]]
    ]

for i in range(2, n):
    temp = []
    temp.append(stairs[i] + max(max_score[i-2]))
    temp.append(stairs[i] + max_score[i-1][0])
    max_score.append(temp)

print(max(max_score[n-1]))