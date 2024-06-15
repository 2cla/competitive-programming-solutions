a,b,c,d = map(int,input().split())
pfs = [0]*(int(1e7)+1)
p = 2
while p<1e7:
    if not pfs[p]: 
        for i in range(p,int(1e7)+1,p):
            pfs[i] += 1
            if not (i//p)%p: pfs[i] = -1e8
    p += 1
ans = 0
for i in range(1,int(1e7)+1):
    if pfs[i]<0: continue
    if pfs[i]&1: ans -= (d//i - (c-1)//i) * (b//i - (a-1)//i)
    else: ans += (d//i - (c-1)//i) * (b//i - (a-1)//i)
print(ans)