import re

pattern = re.compile("(100+1+|01)+")
n = int(input())

for i in range(n):
    wave = input()
    m = re.fullmatch(pattern, wave)
    print("YES" if m else "NO")
    