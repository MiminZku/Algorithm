n = int(input())
age_lst = [[] for _ in range(201)]
for _ in range(n):
    age, name = input().split()
    age_lst[int(age)].append(name)
for i in range(201):
    if age_lst[i]:
        for name in age_lst[i]:
            print(i,name)