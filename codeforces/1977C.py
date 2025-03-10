from math import lcm
def check(p,a):
    c,l=0,1
    for aa in a:
        l2=lcm(l,aa)
        if p%l2:continue
        l=l2
        c+=1
    return c if l==p else 0
t=int(input())
def solve():
    n=int(input())
    a=[int(x) for x in input().split()]
    a.sort()
    t,cont=1,1
    for aa in a:
        t=lcm(aa,t)
        if t>a[-1]:cont=0;break
    if not cont:print(n);return
    aset=set(a)
    p,n=1,a[-1]
    ans=0
    while p*p<=n:
        if not n%p:
            if p not in aset:ans=max(ans,check(p,a))
            if n//p not in aset:ans=max(ans,check(n//p,a))
        p+=1
    print(ans)
for _ in range(t):solve()