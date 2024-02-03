import sys

input = sys.stdin.readline

tc = int(input())

for i in range(tc):
    n = int(input())
    seq = list(map(int, input().split()))
    chk = [False for _ in range(n+1)]
    cycle = 0
    for (i, n) in enumerate(seq):
        next = i
        if chk[next]:
            continue
        cycle += 1
        while not chk[next]:
            chk[next] = True
            next = seq[next-1]
    print(cycle)
