from collections import defaultdict
from itertools import combinations

def bounds_check(x, i_len, j_len):
    i, j = x
    if 0 <= i < i_len and 0 <= j < j_len:
        return True
    return False

def find_antinodes(a, b):
    ax, ay = a
    bx, by = b
    dx = bx - ax
    dy = by - ay
    an1 = (bx + dx, by + dy)
    an2 = (ax - dx, ay - dy)
    return [an1, an2]

def find_antinodes_p2(a, b, i_len, j_len):
    ax, ay = a
    bx, by = b
    dx = bx - ax
    dy = by - ay
    an1 = (bx, by)
    an2 = (ax, ay)
    current_ax, current_ay = an1
    current_bx, current_by, = an2
    antinodes = []
    while bounds_check((current_ax, current_ay), i_len, j_len):
        antinodes.append((current_ax, current_ay))
        current_ax += dx
        current_ay += dy
    while bounds_check((current_bx, current_by), i_len, j_len):
        antinodes.append((current_bx, current_by))
        current_bx -= dx
        current_by -= dy
    
    return antinodes

def one():
    f = open('debuginput.txt').read().strip()
    lines = f.split('\n')
    map = [list(x) for x in lines]
    x_len = len(map)
    y_len = len(map[0])
    print(x_len)
    print(y_len)

    antennae = defaultdict(list)
    for i in range(x_len):
        for j in range(y_len):
            if map[i][j] != '.':
                antennae[map[i][j]].append((i, j))

    antinodes = set()
    for key in antennae:
        # For antennae pick 2
        for combination in combinations(antennae[key], 2):
            # returns pair without bounds check
            results = find_antinodes(combination[0], combination[1]) 
            for result in results:
                if bounds_check(result, x_len, y_len):
                    antinodes.add(result)

    print(len(antinodes))

def two():
    f = open('input.txt').read().strip()
    lines = f.split('\n')
    map = [list(x) for x in lines]
    x_len = len(map)
    y_len = len(map[0])

    antennae = defaultdict(list)
    for i in range(x_len):
        for j in range(y_len):
            if map[i][j] != '.':
                antennae[map[i][j]].append((i, j))
                print(f'{i}, {j}')

    antinodes = set()
    for key in antennae:
        # For antennae pick 2
        for combination in combinations(antennae[key], 2):
            # returns pair without bounds check
            results = find_antinodes_p2(combination[0], combination[1], x_len, y_len) 
            for result in results:
                antinodes.add(result)
    print(antinodes)
    print(len(antinodes))
two()
