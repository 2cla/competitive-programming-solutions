def pow(x,y,m):
    if y == 0: return 1
    p = pow(x,y//2,m) % m
    p = (p*p) % m
    if y%2==0: return p
    else: return (x*p) % m

n,k,m = map(int,input().split())
ml = m.bit_length()
if k > ml or n > m: print(0); exit(0)
mod = 998244353
facts,invfacts = [1]*(m+1),[1]*(m+1)
for i in range(1,m+1): facts[i] = facts[i-1]*i % mod
invfacts[-1] = pow(facts[-1],mod-2,mod)
for i in range(m-1,0,-1): invfacts[i] = invfacts[i+1]*(i+1) % mod
choi = [0]*(m+1)
for i in range(1,m+1):
    ct,tmp,zeros = 0,i,ml-i.bit_count()
    for j in range(ml-1,-1,-1):
        if tmp&(1<<j): continue
        zeros -= 1
        if tmp+(1<<j) > m: continue
        tmp += 1<<j
        ct += 1<<zeros
    ct += 1
    if ct >= n: choi[i] = facts[ct]*invfacts[ct-n]*invfacts[n] % mod
pie = [0]*(ml+1)
for i in range(k,ml+1):
    for j in range(i+1,ml+1): pie[j] += (1-pie[i])*facts[j]*invfacts[j-i]*invfacts[i] % mod
cnts = [0]*(ml+1)
for i in range(1,m+1):
    if i.bit_count() < k: continue
    cnts[i.bit_count()] += choi[i] % mod
ans = 0
for i in range(k,ml+1): ans += (1-pie[i])*cnts[i] % mod
print(ans*facts[n] % mod)