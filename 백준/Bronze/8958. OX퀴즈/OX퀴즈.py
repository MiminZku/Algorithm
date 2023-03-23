t = int(input())
for _ in range(t):
    string = input()
    sum = 0
    score = 1
    for c in string:
        if c == 'O':
            sum += score
            score += 1
        else:
            score = 1
    print(sum)