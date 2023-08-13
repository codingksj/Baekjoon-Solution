def IsValid(data:str, parity:str):
    count = data.count("1")
    if count%2 == int(parity):
        return True
    else:
        return False
    
test = int(input())

for _ in range(test):
    count = 0
    code = input()
    length = len(code)
    for i in range(0,length,8):
        data, parity = code[i:i+7], code[i+7]
        if not IsValid(data, parity):
            count = count+1
    print(count)