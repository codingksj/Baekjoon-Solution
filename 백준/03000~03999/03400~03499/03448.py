def calc_correctness(lines :str) -> float:
    a = len(lines)
    r = a - lines.count('#')
    
    ans = round(r/a*100 , 1)
    
    return ans
    

tc = int(input())

for i in range(tc):
    lines = ""
    while True:
        line = input()
        if line == "":
            break
        lines+=line

    eff = calc_correctness(lines)
    if str(eff).split('.')[-1] == '0':
        eff = int(eff)

    print(f"Efficiency ratio is {eff}%.")