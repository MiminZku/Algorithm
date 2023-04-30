c = int(input())
for _ in range(c):
    scores = list(map(int,input().rstrip().split()))
    avg = sum(scores[1:])/scores[0]
    count = 0
    for i in range(1,scores[0]+1):
        if scores[i] > avg:
            count += 1
    print(f"{(count/scores[0]*100):.3f}%")