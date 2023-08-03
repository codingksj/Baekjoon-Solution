for _ in range(3):
    test = int(input())
    sum = 0
    for i in range(test):
        n = int(input())
        sum += n
        
    if sum > 0:
        print("+")
    elif sum < 0:
        print("-")
    else:
        print("0") 
    