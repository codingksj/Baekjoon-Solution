def convert_to_base_n(base : int, num : int) -> str:
    digits = "0123456789"
    result = ""
    
    if num == 0:
        return "0"
    
    while num > 0:
        r = num % base
        result = digits[r] + result
        num //= base
        
    return result

while True:
    line = input()
    if line=="0":
        break
    base, p, m = line.split()
    
    base = int(base)
    
    p = int(p, base)
    m = int(m, base)
    r = p % m
    
    result = convert_to_base_n(base , r)
    print(result)

    
    