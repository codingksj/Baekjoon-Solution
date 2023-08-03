test = int(input())
for i in range(test):
    blank = input()
    
    total = 0
    n = int(input())
    for j in range(n):
        candy = int(input())
        total += candy
    if not (total % n) :
        print("YES")
    else:
        print("NO")