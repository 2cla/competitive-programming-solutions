import math
def pow(a,b,p):
    if b==0: return 1
    ans = pow(a,b//2,p) % p
    ans = (ans*ans) % p
    if b%2: return (ans*a) % p
    return ans%p

def totient(x):
    ans = x
    p = 2
    while p*p<=x:
        if not x%p:
            while not x%p:
                x //= p
            ans -= ans//p
        p += 1
    if x > 1: ans -= ans//x
    return ans

t = int(input())
for _ in range(t):
    k,c = map(int,input().split())
    if k==1: print(2)
    elif math.gcd(k,c) != 1: print("IMPOSSIBLE")
    else: 
        x = pow(c,totient(k)-1,k)
        if x*c > k: print(x)
        elif x+k <= int(1e9): print(x+k)
        else: print("IMPOSSIBLE")