import sys; input = lambda:sys.stdin.readline().rstrip()

if __name__ == "__main__":
    n = int(input())
    a = set(map(int,input().split()))
    m = int(input())
    nums = list(map(int,input().split()))
    for i in nums:
        if i in a:
            print(1)
        else:
            print(0)