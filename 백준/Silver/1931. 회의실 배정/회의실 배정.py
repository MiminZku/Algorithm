n = int(input())
meetings = [list(map(int,input().rstrip().split())) for _ in range(n)]
meetings.sort(key=lambda x : (-x[0],-x[1]))
count = 1
finish_time = meetings.pop(0)[0]
for i in meetings:
    if i[1] > finish_time: continue
    count += 1
    finish_time = i[0]
print(count)