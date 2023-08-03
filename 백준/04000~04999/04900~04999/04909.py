while True:
    scores = sorted(list(map(int, input().split())))
    if sum(scores) == 0:
        break
    scores = scores[1:-1]
    res = sum(scores)/4
    print(res if sum(scores)%4 else int(res))