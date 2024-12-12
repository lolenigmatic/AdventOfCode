import re

def one():
    with open('3.txt', 'r') as file:
        data = file.read()
        wedidit = re.findall("mul\(\d+,\d+\)", data)
        total = 0
        for cock in wedidit:
            a = cock.split(',')
            total += int(a[0][4:]) * int(a[1][:len(a[1])-1])
         
        print(total)

def two():
    with open('3.txt', 'r') as file:
        data = file.read()
        wedidit = re.findall("mul\(\d+,\d+\)|do\(\)|don't\(\)", data)
        total = 0
        do = True
        for cock in wedidit:
            if cock == "do()":
                do = True
            elif cock == "don't()":
                do = False
            else:
                if do:
                    a = cock.split(',')
                    total += int(a[0][4:]) * int(a[1][:len(a[1])-1])
         
        print(total)

print(two())