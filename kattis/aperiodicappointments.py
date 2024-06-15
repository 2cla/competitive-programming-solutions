n,k = map(int,input().split())
p = [1]
while p[-1]<1e9: p.append(p[-1]*k+1)
if k<len(p) and n>p[k]: print(n-k**k); exit(0)
ans = 0
for i in range(len(p)-1,0,-1):
    ans += (n//p[i])*p[i-1]
    n%=p[i]
print(ans)