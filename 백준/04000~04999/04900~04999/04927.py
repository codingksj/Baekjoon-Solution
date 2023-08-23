def hindu_check(line : str) -> bool:
    front, end = line.split("=")
    op = "*" if front.find("*")!=-1 else "+"
    a,b = front.split(op)
    c,_ = end.split(".")
    
    sum_a = sum(int(digit) for digit in a)
    sum_b = sum(int(digit) for digit in b)
    sum_c = sum(int(digit) for digit in c)
    
    if op == "+":
        return (sum_a + sum_b) % 9 == (sum_c % 9)
    else:
        product_ab = sum_a * sum_b
        return product_ab % 9 == sum_c % 9

tc = 0
while True:
    tc+=1
    line = input()
    if line == ".":
        break
    result = "PASS" if hindu_check(line) else "NOT!"
    print(f"{tc}. {result}")
    