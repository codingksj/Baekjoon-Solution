import re

machine_code = input()
op_list = re.split('(?=[A-Z])',machine_code)
count = 0
nop = 0

for i, op in enumerate(op_list):
    if op == "" or i == len(op_list)-1:
        continue
    nop = len(op) % 4
    if nop != 0:
        count += (4 - nop)

print(count)
