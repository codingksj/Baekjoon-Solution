import sys

input = sys.stdin.readline

tc = int(input())

for _ in range(tc):
    a, b, c = map(int, input().split())
    print(min(a, b, c))