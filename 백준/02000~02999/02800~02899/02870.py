import re

def extract_number_in_line(numbers : list[int],
                           line : str):
    extracted_number : list[int] = list(re.split("\\D", line))
    
    for ex_num in extracted_number:
        if ex_num: 
            numbers.append(int(ex_num))

n = int(input())
numbers : list[int] = []

for i in range(n):
    line = input()
    extract_number_in_line(numbers, line)

numbers.sort()

for number in numbers:
    print(number)