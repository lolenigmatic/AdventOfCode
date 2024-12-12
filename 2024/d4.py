xmas = {
    0: "X",
    1: "M",
    2: "A",
    3: "S"
}

dirs = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    
def check_xmas_real(i, j, dir, grid):
    # dir: diag is (1, 1), right->left is (0, 1), top -> down is (-1, 0)
    curr_i = i
    curr_j = j
    curr_letter = 0
    for i in range(3):
        curr_i += dir[0]
        curr_j += dir[1]
        curr_letter += 1
        if curr_i < 0 or curr_j < 0 or curr_i > len(grid) - 1 or curr_j > len(grid[i]) - 1:
            return False
        if xmas[curr_letter] == grid[curr_i][curr_j]:
            if xmas[curr_letter] == 'S':
                return True
        else:
            return False

def one():
    with open('4.txt') as file:
        grid = []
        result = 0
        for line in file:
            arr = []
            for char in line.rstrip():
                arr.append(char)
            grid.append(arr)

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "X":
                    for dir in dirs:
                        if check_xmas_real(i, j, (dir[0], dir[1]), grid):
                            result += 1
                            #print(f"found at {i} {j} direction: ({dir[0]}, {dir[1]})")
                            #print(f"{i} {j}")
                        
                            
        print(result)

# Upright
# M M
#  A
# S S

upright = {}
upright[(-1, -1)] = "M"
upright[(-1, 1)] = "M"
upright[(1, 1)] = "S"
upright[(1, -1)] = "S"
x_dir = [(1, 1), (-1, 1), (-1, -1), (1, -1)]

def check_x_mas(i, j, grid):
    x_dict = {}
    for dir in x_dir:
        if i + dir[0] < 0 or j + dir[1] < 0 or i + dir[0] > len(grid) - 1 or j + dir[1] > len(grid[i]) - 1:
            return False
        x_dict[dir] = grid[i + dir[0]][j + dir[1]] 
    
    for i in range(4):
        if upright == x_dict:
            return True
        
        x_dict_new = {}
        x_dict_new[(-1, 1)] = x_dict[(-1, -1)]
        x_dict_new[(1, 1)] = x_dict[(-1, 1)]
        x_dict_new[(1, -1)] = x_dict[(1, 1)]
        x_dict_new[(-1, -1)] = x_dict[(1, -1)]

        x_dict = x_dict_new
    
    return False


def two():
    with open('4.txt') as file:
        grid = []
        result = 0
        for line in file:
            arr = []
            for char in line.rstrip():
                arr.append(char)
            grid.append(arr)

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "A":
                    if check_x_mas(i, j, grid):
                        result += 1
                            
        print(result)

two()


                
