
def Main():
    spots = []
    N = int(input())

    for _ in range(N):
        x , y = input().split()
        temp = []
        temp.append(int(x))
        temp.append(int(y))
        spots.append(temp)
    
    result = Sort(spots)
    for spot in result:
        print(spot[0],spot[1])


def Sort(list):
    if(len(list) <= 1):
        return list

    mid = len(list)//2
    left = Sort(list[0:mid])
    right = Sort(list[mid:])
    sortedList = []
    l = 0; r = 0
    while(l <= len(left) and r <= len(right)):
        if(l == len(left)):
            sortedList = sortedList + right[r:]
            break
        if(r == len(right)):
            sortedList = sortedList + left[l:]
            break

        if(left[l][1] == right[r][1]):
            if(left[l][0] < right[r][0]):
                sortedList.append(left[l])
                l = l + 1
            else:
                sortedList.append(right[r])
                r = r + 1
        elif(left[l][1] < right[r][1]):
            sortedList.append(left[l])
            l = l + 1
        else:
            sortedList.append(right[r])            
            r = r + 1
        
    return sortedList

if __name__ == '__main__':
    Main()