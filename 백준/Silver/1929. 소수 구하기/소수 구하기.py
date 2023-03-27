m, n = map(int, input().split())

def prime_list(m, n):
    prime = [True] * (n+1)
    prime[0], prime[1] = False, False
    tmp = int(n**0.5)
    for i in range(2, tmp+1):
        if prime[i] == True:
            for j in range(2*i, n+1, i):
                prime[j] = False
    return [i for i in range(m, n+1) if prime[i] == True]


for i in prime_list(m, n):
    print(i)