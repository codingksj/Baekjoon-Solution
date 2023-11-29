def get_digital_root(num: str) -> int:
    total = sum(int(digit) for digit in num)

    while total >= 10:
        total = sum(int(digit) for digit in str(total))
    
    return total

while True:
    num = input()
    if num == "0":
        break
    print(get_digital_root(num))
