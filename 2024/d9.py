def one():
    input = open('9.txt').read().strip()
    disk = []
    for i in range(0, len(input)- 1, 2):
        disk.extend([str(i//2)] * int(input[i]))
        disk.extend(['.'] * int(input[i+1]))
        
    disk.extend([str((i+2)//2)] * int(input[-1]))

    i = disk.index('.') # empty space pointer from left
    j = len(disk) - 1 # non empty space pointer from right

    while i < j:
        # Do disk replacement
        disk[i] = disk[j]
        disk[j] = '.'
        # Look for next empty space
        while True:
            i += 1
            if disk[i] == '.':
                break
        
        # Look for next non-empty space
        while True:
            j -= 1
            if disk[j] != '.':
                break
    
    total = 0   
    for i, val in enumerate(disk):
        if val == '.':
            break
        total += i * int(val)
    print(total)

def find_cont_gap(disk, size):
    for i, (x, y) in enumerate(disk):
        if x == '.' and y >= size:
            return (i, y)
    return (None, None)

# returns tuple (id, size)
def find_partition_index(disk, part_id):
    for i, (x, y) in enumerate(disk):
        if x == part_id:
            return (i, y)
    return (None, None)

def reconstruct_disk(disk):
    new_disk = []
    for entry in disk:
        index, size = entry
        for i in range(size):
            new_disk.append(index)

    return new_disk


def two():
    input = open('9.txt').read().strip()
    disk = []
    for i in range(0, len(input)- 1, 2):
        disk.append((str(i//2), int(input[i])))
        disk.append(('.', int(input[i+1])))
        current_id = i//2

    disk.append((str((i+2)//2), int(input[-1])))
    # start with max id partition
    for id in range(current_id + 1, 0, -1):
        index, size = find_partition_index(disk, str(id))
        gap_index, gap_size = find_cont_gap(disk, size)
        
        #If no suitable space for disk, move on
        if gap_index is None or gap_index > index:
            continue

        disk[index] = ('.', size)
        if gap_size > size:
            disk.insert(gap_index + 1, ('.', gap_size - size))
        disk[gap_index] = (str(id), size)

    disk_better = reconstruct_disk(disk)

    total = 0  
    for i, val in enumerate(disk_better):
        if val == '.':
            continue
        total += i * int(val)
    print(total)

two()