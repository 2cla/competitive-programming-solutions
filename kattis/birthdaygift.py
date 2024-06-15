import time
a,b = map(int,input().split())
d,mod,n = {},int(1e9+7),1
asfa = time.time()
d[n] = [[0]*90 for _ in range(90)]
for i in range(90):
    for k in range(10):
        if k==i%10: continue
        d[n][i][((i//10+k)%9)*10+k] += 1
for _ in range(60):
    n *= 2
    d[n] = [[0]*90 for _ in range(90)]
    for i1 in range(90):
        for i2 in range(90):
            for i3 in range(90):
                d[n][i1][i2] += d[n//2][i1][i3]*d[n//2][i3][i2]
            d[n][i1][i2] %= mod

print(time.time()-asfa)
st = [0]*90; st[0] = 1
ans = 0
if a > 2:
    a -= 2
    for c in range(61):
        if a&(1<<c):
            st2 = [0]*90
            for i1 in range(90):
                for i2 in range(90):
                    st2[i1] += st[i2]*d[1<<c][i2][i1]
            st = [x%mod for x in st2]
    for i1 in range(90):
        for i2 in range(10):
            for i3 in range(10):
                if ((i1//10)*100+i2*10+i3)%225 == b:
                    if i1%10 == i2 or i2 == i3: continue
                    ans += st[i1] % mod
else:
    if a==2:
        for i2 in range(1,10):
            for i3 in range(10):
                if (i2*10+i3)%225 == b:
                    if i2 == i3: continue
                    ans += 1
    else:
        for i3 in range(1,10):
            if i3%225 == b: ans += 1
print(ans % mod)