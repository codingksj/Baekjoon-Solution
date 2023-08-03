test = int(input())
ans = 0
for i in range(test):
    walks = input()
    pos = walks.find('D')
    if pos == -1:
        ans = len(walks)
    else:
        ans = len(walks[:pos])
    print(ans)
    