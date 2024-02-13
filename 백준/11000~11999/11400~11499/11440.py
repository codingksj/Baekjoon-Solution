import sys

input = sys.stdin.readline

MOD = (int)((1E+9)+7)

def F(n : int) -> int:
    if dp.get(n) :
        return dp[n]
    
    k = n//2
    dp[n] = (F(k)**2 + F(k+1)**2) % MOD if n&1 else (F(k+1)**2 - F(k-1)**2) % MOD
    
    return dp[n]
    
n = int(input())
dp = dict()

dp[0] = 0
dp[1] = 1
dp[2] = 1

print((F(n) * F(n+1)) % MOD)
