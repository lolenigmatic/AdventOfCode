from copy import copy
import time

def guard_in_bounds(position, i_lim, j_lim):
    i, j = position
    if 0 <= i < i_lim and 0 <= j < j_lim:
        return True
    return False

dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)] # N E S W

def run_it(starting_pos, obstacles, i_lim, j_lim):
    guard_pos = starting_pos
    cur_dir = 0
    pos_history = set([(guard_pos[0], guard_pos[1], cur_dir)])
    while guard_in_bounds(guard_pos, i_lim, j_lim):
            i, j = dirs[cur_dir]
            if guard_in_bounds((guard_pos[0] + i, guard_pos[1] + j), i_lim, j_lim) and (guard_pos[0] + i, guard_pos[1] + j) in obstacles:
                cur_dir = (cur_dir + 1) % 4
                continue
            guard_pos = (guard_pos[0] + i, guard_pos[1] + j)
            if (guard_pos[0], guard_pos[1], cur_dir) in pos_history:
                return None
            pos_history.add((guard_pos[0], guard_pos[1], cur_dir))

    return pos_history

def one():
    f = open('6.txt').read().strip()
    grid = f.split('\n')
    i_lim = len(grid)
    j_lim = len(grid[0])
    guard_pos = (0, 0)
    obstacles = set()
    for i in range(i_lim):
        for j in range(j_lim):
            if grid[i][j] == '^':
                guard_pos = (i, j)
            elif grid[i][j] == '#':
                obstacles.add((i, j))

    history = run_it(guard_pos, obstacles, i_lim, j_lim)
    locations_tried = set([])
    for i, j, dir in history:
        if guard_in_bounds((i, j), i_lim, j_lim):
            locations_tried.add((i, j))
    
    print(len(locations_tried))

def two():
    f = open('6.txt').read().strip()
    grid = f.split('\n')
    i_lim = len(grid)
    j_lim = len(grid[0])
    guard_pos = (0, 0)
    obstacles = set()
    for i in range(i_lim):
        for j in range(j_lim):
            if grid[i][j] == '^':
                guard_pos = (i, j)
            elif grid[i][j] == '#':
                obstacles.add((i, j))

    orig_history = run_it(guard_pos, obstacles, i_lim, j_lim)
    
    locations_tried = set([])
    potential_blockers = set([])
    for location in orig_history:
        if (location[0], location[1]) in locations_tried or (location[0] == guard_pos[0] and location[1] == guard_pos[1]) or not guard_in_bounds((location[0], location[1]), i_lim, j_lim):
            continue
        new_obs = copy(obstacles)
        new_obs.add((location[0], location[1]))
        if not run_it(guard_pos, new_obs, i_lim, j_lim):
            potential_blockers.add((location[0], location[1]))

    print(len(potential_blockers))
        
start = time.time()
one()
end = time.time()
print(f"time: {end - start}")