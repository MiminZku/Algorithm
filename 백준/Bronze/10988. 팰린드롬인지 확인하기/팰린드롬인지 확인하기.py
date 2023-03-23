import sys

def Main():
    print(IsPalindrome(sys.stdin.readline().rstrip()))

def IsPalindrome(string):
    length = len(string)
    for i in range(length//2):
        if string[i] != string[length-1-i]:
            return 0
    return 1

if __name__ == '__main__':
    Main()