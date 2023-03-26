n = int(input())
count = 0
i = 666
while True:
    num = str(i)
    i += 1
    if '666' in num:
        count += 1
    if n == count:
        print(num)
        break