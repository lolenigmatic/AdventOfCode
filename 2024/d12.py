import time

dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]
orthogonal = [(dirs[0], dirs[1]), (dirs[0], dirs[2]), (dirs[1], dirs[3]), (dirs[2], dirs[3])]

def get_region(i, j, grid, visited):
    i_lim = len(grid)
    j_lim = len(grid[0])
    plant = grid[i][j]
    visited.add((i, j))
    for di, dj in dirs:
        if 0 <= i+di < i_lim and 0 <= j+dj < j_lim and grid[i+di][j+dj] == plant and (i+di, j+dj) not in visited:
            get_region(i+di, j+dj, grid, visited)
    return visited

def get_perimeter(region):
    perim = 0
    for i, j in region:  
        for di, dj in dirs:
            if (i+di, j+dj) not in region:
                    perim += 1
    return perim

# This actually counts corners
def get_sides(edges):
    corners = 0
    for point in edges:
        x, y = point
        for dir1, dir2 in orthogonal:
            di1, dj1 = dir1
            di2, dj2 = dir2
            # Count external corners
            if (x+di1, y+dj1) not in edges and (x+di2, y+dj2) not in edges:
                corners += 1
            
            # Get diagonals, count internal corners
            di, dj = (di1+di2, dj1+dj2)
            if (x+di1, y+dj1) in edges and (x+di2, y+dj2) in edges and (x+di, y+dj) not in edges:
                corners += 1
    return corners

def one():
    f = open('12.txt').read().strip()
    grid = f.split('\n')
    in_region = set()
    regions = []
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if (i, j) in in_region:
                continue
            region = get_region(i, j, grid, set())
            in_region = in_region.union(region)
            regions.append(region)
    total = 0
    for region in regions:
         total += get_perimeter(region) * len(region)
    print(total)

def two():
    f = open('12.txt').read().strip()
    grid = f.split('\n')
    in_region = set()
    regions = []
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if (i, j) in in_region:
                continue
            region = get_region(i, j, grid, set())
            in_region = in_region.union(region)
            regions.append(region)
    
    total = 0
    for region in regions:
         total += get_sides(region) * len(region)
    print(total)

start = time.time()
two()
end = time.time()
print(f"time: {end - start}")