def one():
    with open('1.txt') as file:
        left = []
        right = []
        for line in file:
            nums = line.split('   ')
            left.append(nums[0])
            right.append(nums[1])

        left.sort()
        right.sort()

        total = 0

        for i in range(len(left)):
            total += abs(int(left[i]) - int(right[i]))

        return total
    
def two():
    with open('1.txt') as file:
        left = []
        right = []
        for line in file:
            nums = line.split('   ')
            left.append(int(nums[0]))
            right.append(int(nums[1]))
        
        total = 0
        for num in left:
            total += num * right.count(num)

        return total
    
print(two())