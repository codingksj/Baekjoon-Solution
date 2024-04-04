import sys

input = sys.stdin.readline

def mod_pow(base : int, exp : int, mod : int) -> int:
    res : int = 1
    
    while exp:
        if exp & 1:
            res =  (res * base) % mod
        base = (base * base) % mod
        exp >>= 1
    
    return res % mod
        
a, b, c = map(int, input().split())

print(mod_pow(a, b, c))