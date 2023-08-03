P, K = map(int, input().split())
isGood = True
for i in range(2,K):
    if P % i == 0:
        print('BAD', i)
        isGood = False
        break
if isGood:
    print('GOOD')