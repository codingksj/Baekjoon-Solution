def AccuratePowerOf2(n : int) -> str:
    answer : str = "%.256f" % (2**(-n))
    index = len(answer)
    for i in range(index-1,-1,-1):
        if answer[i] != "0":
            break
        answer = answer[:i]
    
    return answer
    
n = int(input())
print(AccuratePowerOf2(n))