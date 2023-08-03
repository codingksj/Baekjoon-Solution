while True:
    line = int(input())
    if line == 0:
        break
    else:
        for i in range(1,line+1):
            print("*"*i)