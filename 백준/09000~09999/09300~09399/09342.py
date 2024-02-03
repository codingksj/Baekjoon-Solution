import sys
import re

input = sys.stdin.readline
pattern = re.compile("^[A-F]?A+F+C+[A-F]?$")
tc = int(input())

for i in range(tc):
    genome = input()
    print("Infected!" if pattern.match(genome) else "Good")