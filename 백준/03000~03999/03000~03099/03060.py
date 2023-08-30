tc = int(input())

for _ in range(tc):
    n = int(input())
    pigs = list(map(int, input().split()))
    feed = sum(pig for pig in pigs)
    day = 1
    while n >= feed:
        day += 1
        feed *= 4

    print(day)