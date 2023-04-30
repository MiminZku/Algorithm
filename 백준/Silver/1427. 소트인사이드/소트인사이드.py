n = input()
arr = [0]*10
for c in n:
    arr[int(c)] += 1

for i in range(9, -1, -1):
    if arr[i]==0:    continue
    for _ in range(arr[i]):
        print(i,end = "")