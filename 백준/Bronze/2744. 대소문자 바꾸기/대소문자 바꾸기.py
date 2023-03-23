string = input()
for c in string:
    if ord(c)>=97:
        print(c.upper(),end="")
    else:
        print(c.lower(),end="")