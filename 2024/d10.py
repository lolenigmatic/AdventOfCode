dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def find_score(curr, grid, hist):
    i_lim = len(grid)
    j_lim = len(grid[0])
    i, j = curr
    hist = hist + [curr]
    if grid[i][j] == '9':
        return {curr}
    total = set()
    for dir in dirs:
        di, dj = dir
        if 0 <= i+di < i_lim and 0 <= j+dj < j_lim and int(grid[i+di][j+dj]) == int(grid[i][j]) + 1:
            total = total.union(find_score((i+di, j+dj), grid, hist))
    return total

def find_rating(curr, grid, hist):
    i_lim = len(grid)
    j_lim = len(grid[0])
    i, j = curr
    hist = hist + [curr]
    if grid[i][j] == '9':
        return 1
    total = 0
    for dir in dirs:
        di, dj = dir
        if 0 <= i+di < i_lim and 0 <= j+dj < j_lim and int(grid[i+di][j+dj]) == int(grid[i][j]) + 1:
            total += find_rating((i+di, j+dj), grid, hist)
    return total

def one():
    f = open('10.txt').read().strip()
    grid = f.split('\n')
    answer = 0
    for i in range(0, len(grid)):
        for j in range(0, len(grid)):
            if grid[i][j] == '0':
                answer += len(find_score((i,j), grid, []))
    print(answer)

def two():
    f = open('10.txt').read().strip()
    grid = f.split('\n')
    answer = 0
    for i in range(0, len(grid)):
        for j in range(0, len(grid)):
            if grid[i][j] == '0':
                answer += find_rating((i, j), grid, [])
    print(answer)


one()
two()