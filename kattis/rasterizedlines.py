from itertools import product
def gen_primes(n):
    primes = [True]*(n+1)
    p = 2
    while p*p<=n:
        if not primes[p]: p += 1; continue
        for i in range(2*p,n+1,p):
            primes[i] = False
        p += 1
    primes = [x for x,y in enumerate(primes) if y][2:]
    return primes

def prime_factorize(n):
    factors = {}
    for p in primes:
        if p*p>n: break
        while not n%p:
            factors[p] = factors.get(p,0) + 1
            n //= p
    if n > 1: factors[n] = factors.get(n,0) + 1
    return factors

def totient(n,factors):
    ans = n
    for p in factors.keys():
        while not n%p:
            n //= p
        ans -= ans//p
    return ans

t = int(input())
primes = gen_primes(int(1e7))
for _ in range(t):
    n = int(input())
    factors = prime_factorize(n)
    for k,v in factors.items():
        te = [k**e for e in range(v+1)]
        factors[k] = tuple(te)
    combs = product(*factors.values())
    ans = 0
    for c in combs:
        te = 1
        for i in c: te *= i
        factors = prime_factorize(te+1)
        ans += totient(te+1,factors)
    print(ans)