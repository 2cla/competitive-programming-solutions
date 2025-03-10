t=int(input())
def solve():
    n=int(input())
    arr=[int(x) for x in input().split()]
    pre=[(arr[0],0)]
    for i,a in enumerate(arr):
        if not i:continue
        if a+i<sum(pre[-1]):pre.append((a,i))
        else:pre.append(pre[-1])
    for i in range(1,n):
        if i-arr[i]>=0:
            p1,p2=pre[i-arr[i]]
            if i-p2+1>max(p1,arr[i]):
                print(0)
                return
    amax,amin=n-1,0
    for i,a in enumerate(arr):
        amax=min(amax,i-1+a)
        amin=max(amin,i-a+1)
    print(amax-amin+1)
for _ in range(t):solve()