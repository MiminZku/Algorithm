def Change(i):
    return ord(i)-96

n = int(input())
alphabets = list(map(Change,list(input())))
sum = 0
for i in range(n):
    sum += alphabets[i] * 31**i
print(sum)