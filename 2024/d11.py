import math
from collections import defaultdict

def digits(n):
    return int(math.log10(n))+1

def blink(rocks):
    new_rocks = []
    for rock in rocks:
        if rock == 0:
            new_rocks.append(1)
        elif digits(rock) % 2 == 0:
            str_rock = str(rock)
            new_rocks.append(int(str_rock[0:len(str_rock)//2]))
            new_rocks.append(int(str_rock[len(str_rock)//2:]))
        else:
            new_rocks.append(rock * 2024)
    return new_rocks

def blink_dict(rocks):
    new_rocks = defaultdict(int)
    for key, value in rocks.items():
        if key == 0:
            new_rocks[1] += value
        elif digits(key) % 2 == 0:
            str_rock = str(key)
            new_rocks[int(str_rock[0:len(str_rock)//2])] += value
            new_rocks[int(str_rock[len(str_rock)//2:])] += value
        else:
            new_rocks[key * 2024] += value
    return new_rocks

def one():
    f = open('11.txt').read().strip()
    rocks = [int(x) for x in f.split(' ')]
    for i in range(25):
        rocks = blink(rocks)

    print(len(rocks))

def two():
    f = open('11.txt').read().strip().split(' ')
    rocks = defaultdict(int)
    for i in f:
        rocks[int(i)] += 1
    
    for i in range(75):
        rocks = blink_dict(rocks)
    
    total = 0
    for i in rocks.values():
        total += i
    print(total)

one()
two()