def one():
    with open('5.txt', 'r') as file:
        rules = {}
        done_parsing_rules = False
        correct_updates = []
        for line in file:
            if not done_parsing_rules:
                if line.rstrip() == '':
                    print(rules)
                    done_parsing_rules = True
                    continue

                line_strip = line.rstrip()
                split = line_strip.split('|')

                if split[0] in rules:
                    rules[split[0]].append(split[1])

                else:
                    rules[split[0]] = [split[1]]

            else:
                update = line.rstrip().split(',')
                is_correct = True
                for entry in update:
                    if not entry in rules:
                        continue
                    
                    this_rule = rules[entry]
                    for num_to_check in this_rule:
                        if num_to_check in update and update.index(num_to_check) < update.index(entry):
                             is_correct = False
                             break
                    
                if is_correct:
                        correct_updates.append(update)

        sum = 0
        for update in correct_updates:
            print(update)
            sum += int(update[int((len(update) - 1) / 2)])
        return sum 

def two():
    with open('5.txt', 'r') as file:
        rules = {}
        done_parsing_rules = False
        incorrect_updates = []
        for line in file:
            if not done_parsing_rules:
                if line.rstrip() == '':
                    done_parsing_rules = True
                    continue
                line_strip = line.rstrip()
                split = line_strip.split('|')
                if split[0] in rules:
                    rules[split[0]].append(split[1])
                else:
                    rules[split[0]] = [split[1]]
            else:
                update = line.rstrip().split(',')
                is_correct = True
                for entry in update:
                    if not entry in rules:
                        continue
                    this_rule = rules[entry]
                    for num_to_check in this_rule:
                        if num_to_check in update and update.index(num_to_check) < update.index(entry):
                             is_correct = False
                if not is_correct:
                        incorrect_updates.append(update)
        fixed = []
        for incorrect_update in incorrect_updates:
            is_clean = False
            while not is_clean:
                is_clean = True
                for i in range(len(incorrect_update) - 1):
                    # Check with every following value
                    for j in range(i+1, len(incorrect_update)):
                        if incorrect_update[j] in rules and incorrect_update[i] in rules[incorrect_update[j]]:
                            is_clean = False
                            temp = incorrect_update[i]
                            incorrect_update[i] = incorrect_update[j]
                            incorrect_update[j] = temp
                            break
            
            fixed.append(incorrect_update)
        
        sum = 0
        for update in fixed:
            #print(update)
            sum += int(update[int((len(update) - 1) / 2)])
        return sum 

print(two())