def IsSelfReplicatedNum(n : int) -> bool:
    original = str(n)
    length = len(original)
    square = str(n*n)[-length:]
    return original == square

test = int(input())

for i in range(test):
    n = int(input())
    print("YES" if IsSelfReplicatedNum(n) else "NO")