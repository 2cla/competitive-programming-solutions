import math
def prime(n):
    s = round(math.sqrt(n))
    for i in range(2, s+1):
        if n % i == 0: return False
    return True

def squarefactor(n):
    s = round(math.sqrt(n))
    for i in range(2, s+1):
        if n % (i*i) == 0: return True
    return False

def gcd(m, n):
    if m < n: return gcd(n, m)
    if m % n == 0: return n
    return gcd(m - (m // n) * n, n)

a, b = [int(x) for x in input().split()]
if prime(a) and prime(b) and a != b: print("full credit"); exit(0)
if squarefactor(a) or squarefactor(b) or gcd(a, b) != 1: print("no credit"); exit(0)
print("partial credit")