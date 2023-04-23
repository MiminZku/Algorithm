import sys

def merge_sort(lst):
    lst_len = len(lst)
    if lst_len == 1:
        return lst
    
    mid = lst_len//2
    left = merge_sort(lst[0:mid])
    right = merge_sort(lst[mid:])
    merged = []
    l = 0 ; r = 0
    while (l <= len(left) and r <= len(right)):
        if (l == len(left)):
            merged = merged + right[r:]
            break
        if (r == len(right)):
            merged = merged + left[l:]
            break

        if (left[l] == right[r]):
            merged.append(left[l])
            merged.append(right[r])
            l += 1
            r += 1
        elif (left[l] < right[r]):
            merged.append(left[l])
            l += 1
        else:
            merged.append(right[r])            
            r += 1
    return merged

n = int(input())
lst = []
for _ in range(n):
    lst.append(int(sys.stdin.readline()))
for i in merge_sort(lst):
    print(i)