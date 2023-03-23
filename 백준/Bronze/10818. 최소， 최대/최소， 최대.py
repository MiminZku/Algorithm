n = int(input())
nums = list(map(int, input().split()))
max = nums[0] ; min = nums[0]
for i in range(1,n):
    if nums[i] > max:
        max = nums[i]
    elif nums[i] < min:
        min = nums[i]

print(min,max)