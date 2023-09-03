MAX = 32768

def get_primes(n : int) -> list[int]:
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    
    for p in range(2, int(n**0.5) + 1):
        if is_prime[p]:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
    
    primes = [p for p in range(2, n + 1) if is_prime[p]]
    return primes

def prime_base_minus(primes : list[int], n : int) -> str:
    x = n-1
    factors : list[int] = []
    
    for prime in primes:
        count = 0
        while not x % prime:
            x //= prime
            count += 1
        if count:
            factors.append((prime, count))
            
    result = " ".join(f"{prime} {count}" for prime, count in factors)
    
    return result
    
primes = get_primes(MAX)
primes.reverse()

while True:
    line = input()
    if line == "0":
        break
    numbers = list(map(int, line.split()))
    n = 1
    for i in range(len(numbers)//2):
        base = numbers[2*i]
        exponenet = numbers[2*i+1]
        n *= base ** exponenet
    
    result = prime_base_minus(primes, n)
    print(result)
        
    


