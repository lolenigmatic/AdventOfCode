def one():
    with open('2.txt') as file:
        safe = 0
        for line in file:
            nums = [int(x) for x in line.split(' ')]
            decreasing = 1
            if nums[0] > nums[1]:
                decreasing = -1
            
            for i in range(len(nums) - 1):
                delta = (nums[i + 1] - nums[i]) * decreasing
                if delta <= 0:
                    break
                if delta > 3:
                    break
                if i == len(nums) - 2:
                    safe += 1

        return safe
    
def valid(nums):
    decreasing = 1
    if nums[0] > nums[1]:
        decreasing = -1
    
    for i in range(len(nums) - 1):
        delta = (nums[i + 1] - nums[i]) * decreasing
        if delta <= 0 or delta > 3:
            return False
    
    return True

def twobrute():
    with open('2.txt') as file:
        safe = 0
        for line in file:
            nums = [int(x) for x in line.split(' ')]
            for i in range(len(nums)):
                arr = nums.copy()
                arr.pop(i)
                if valid(arr):
                    safe += 1
                    break
        
        return safe



print(twobrute())