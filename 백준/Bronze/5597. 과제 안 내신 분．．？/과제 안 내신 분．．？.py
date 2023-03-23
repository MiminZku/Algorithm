check = [0 for i  in range(30)]

for _ in range(28):
    n = int(input())
    check[n-1] = 1
    
for i in range(30):
    if check[i] == 0:
        print(i+1)