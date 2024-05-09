import sys

sys.setrecursionlimit(2**21)

SRC = 1
VIA = 2
DEST = 3

input = sys.stdin.readline

def hanoi(depth : int, src : int, dest : int, via : int) -> None:
    if depth == 1:
        print(f"{src} {dest}")
        return
    hanoi(depth-1, src, via, dest)
    print(f"{src} {dest}")
    hanoi(depth-1, via, dest, src)

def main():
    n = int(input())
    print((2**n)-1)
    if n<=20:
        hanoi(n, SRC, DEST, VIA)
    
if __name__ == "__main__":
    main()
