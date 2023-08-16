n = int(input())
for i in range(n,0,-1):
    goldnum = str(i)
    is_goldnum = True
    for digit in goldnum:
        if digit not in "47":
            is_goldnum = False
            break
        
    if is_goldnum:
        print(goldnum) 
        break
    else: 
        continue