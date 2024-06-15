import itertools
n,m = map(int,input().split())
grid,mod = [],998244353
for _ in range(n): grid.append([*input()])
mp = {"?":(0,1,2),"I":(0,),"C":(1,),"P":(2,)}
dp = [[0]*(3**(m+1)) for _ in range(m*n-m)]
gen = [mp[x] for x in (grid[0]+[grid[1][0]])]
prods = [*itertools.product(*gen)]
for p in prods:
    num = 0
    for i,j in enumerate(p): num += j*3**i
    dp[0][num] = 1
for i in range(1,m*n-m):
    for j in mp[grid[1+i//m][i%m]]:
        for k in range(3**(m+1)):
            if k%3 == 0 and (k//3)%3 == 1 and j == 1 and (k//(3**m)) == 2 and i%m != 0: continue
            dp[i][j*3**m+k//3] += dp[i-1][k] % mod
tot = 1
for i in range(n): tot *= 3**grid[i].count("?") % mod
print((tot - sum(dp[-1])) % mod)