import math
def is_prime(n):
    factors = prime_factorize(n)
    if len(factors.keys()) > 1: return False
    if [*factors.values()][0] > 1: return False
    return True

def prime_factorize(n):
    factors = {}
    p = 2
    while p*p<=n:
        while not n%p:
            factors[p] = factors.get(p,0) + 1
            n //= p
        p += 1
    if n > 1: factors[n] = factors.get(n,0) + 1
    return factors

x = int(input())
if x==1: print(1); exit(0)
ans = float("inf")
if int(math.sqrt(x))*int(math.sqrt(x)) == x and is_prime(int(math.sqrt(x))): ans = int(math.sqrt(x))
for i in range(2,1001):
    if not is_prime(i): continue
    if i**6 == x: ans = min(ans,i*i)
for i in range(2,40000):
    divs,factors = 1,prime_factorize(i)
    for v in factors.values(): divs *= v+1
    if i**divs == x: ans = min(ans,i)
print(-1) if ans>1e20 else print(ans)