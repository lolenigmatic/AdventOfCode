import itertools
from copy import copy

def combinations(l, n):
    yield from itertools.product(*([l] * n))

"""

[1, 2, 3] affects index 1 and 2
['+', 'a'] a in index 1

"""

def eval(nums, ops):
    total = nums[0]
    for i in range(1, len(nums)):
        if ops[i - 1] == "*":
            total *= nums[i]
        elif ops[i - 1] == "+":
            total += nums[i]
        elif ops[i - 1] == "a":
            total = int(str(total) + str(nums[i]))

    return total

def one():
    f = open('7.txt').read().strip()
    lines = f.split('\n')
    ans = 0

    for line in lines:
        s = line.split(" ")
        exp_result = int(s.pop(0)[:-1])
        nums = [int(x) for x in s]
        ops = combinations('*+', len(nums) - 1)
        for op in ops:
            result = eval(nums, op)
            if result == exp_result:
                ans += result
                break
    print(ans)

def two():
    f = open('7.txt').read().strip()
    lines = f.split('\n')
    ans = 0

    for line in lines:
        s = line.split(" ")
        exp_result = int(s.pop(0)[:-1])
        nums = [int(x) for x in s]
        ops = combinations('*+a', len(nums) - 1)
        for op in ops:
            result = eval(nums, op)
            if result == exp_result:
                ans += result
                break
    print(ans)

two()
#eval([1, 2, 3], ['+', 'a'])