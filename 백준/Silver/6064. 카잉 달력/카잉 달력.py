import sys; input = lambda : sys.stdin.readline().rstrip()

def gcd(a, b): # a > b
    if b==0:
        return a
    return gcd(b, a%b)

def main():
    N = int(input())
    mylist = []
    
    for n in range(N):
        mylist.append(map(int,input().split()))
    for M, N, x, y in mylist:
        result = -1
        if M>N: gcd_val = gcd(M,N)
        else:   gcd_val = gcd(N,M)
        for i in range(N//gcd_val+1):
            if (M*i+x-y)%N == 0:
                result = M*i+x
                break
        print(result)

    return

if __name__ == '__main__':
    main()