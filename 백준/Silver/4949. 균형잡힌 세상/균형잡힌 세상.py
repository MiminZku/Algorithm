import sys; input = lambda:sys.stdin.readline().rstrip()

def count(stack, letter):
    count = 0
    for c in stack:
        if c==letter:
            count+=1
    return count

while True:
    is_wrong = False
    stack = []
    string = input()
    if string == '.':
        break
    for c in string:
        if c == '(' or c == '[':
            stack.append(c)
        elif c == ')':
            if count(stack,'(') == 0:
                is_wrong = True
                break
            last = stack.pop()
            if last == '[':
                stack.append(last)
                is_wrong = True
                break
            
        elif c == ']':
            if count(stack,'[') == 0:
                is_wrong = True
                break
            last = stack.pop()
            if last == '(':
                stack.append(last)
                is_wrong = True
                break
        # print(stack)
    if len(stack) > 0:
        is_wrong = True
    if is_wrong:
        print('no')
    else:
        print('yes')