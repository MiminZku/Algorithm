n = int(input())

lst = [[] for _ in range(51)]
for _ in range(n):
    s = input()
    lst[len(s)].append(s)
for str_lst in lst:
    if str_lst:
        str_lst = sorted(list(set(str_lst)))
        for s in str_lst:
            print(s)