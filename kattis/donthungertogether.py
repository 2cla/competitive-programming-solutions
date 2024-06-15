def solve(mid):
    cons = 0
    for i in range(1,n+1):
        cons = max(exp[i],cons+mid)
        if cons > found[i]: return False
    return True

n,k = map(int,input().split())
found1,exp1 = [0]*(n+1),[0]*(n+1)
for i in range(1,n+1):
    q,f = map(int,input().split())
    found1[i] = q; exp1[f] += q
found,exp = [0]*(n+1),[0]*(n+1)
rsf,rse = 0,0
for i in range(1,n+1): rsf += found1[i]; found[i] = rsf; rse += exp1[i]; exp[i] = rse
for i in range(1,n+1):
    if found1[i] == 0 and found[i-1] == exp[i-1]: print(-1); exit(0)
a,b = 0,1e9
while b-a > 1e-12 and (b-a)/(max(a,b)+1e-9) > 1e-12:
    mid = (a+b)/2
    if solve(mid): a = mid
    else: b = mid
print(mid/k)