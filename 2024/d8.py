from collections import defaultdict
import itertools

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
    an1 = (bx + dx, bx + dy)
    an2 = (ax - dx, ax - dy)
    return (an1, an2)

def one():
    f = open('8.txt').read().strip()
    lines = f.split('\n')
    map = [list(x) for x in lines]
    x_len = len(map)
    y_len = len(map[0])

    antennae = defaultdict(list)
    for i in range(x_len):
        for j in range(y_len):
            if map[i][j] != '.':
                antennae[map[i][j]].append((i, j))

    antinodes = set()

one()