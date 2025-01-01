from math import log
n = int(input())
gears = {}
for _ in range(n):
    s,c = map(int,input().split())
    if s in gears: gears[s].append(c)
    else: gears[s] = [c]
ans = 0
for k,v in gears.items():
    v = sorted(v)
    for i in range(len(v)//2):
        la,sm = v[len(v)-1-i],v[i]
        ans += log(la)-log(sm)
print(ans)