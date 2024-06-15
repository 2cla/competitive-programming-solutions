import sys; sys.setrecursionlimit(10000);
def dpf(n):
    factors = []
    p = 2
    while p*p<=n:
        if not n%p: factors.append(p)
        while not n%p: n //= p
        p += 1
    if n<101 and n!=1: factors.append(n)
    return tuple(factors)
def dfs(node):
    vis.add(node)
    for c in g[node]:
        if c not in vis: t[node] = t.get(node,[])+[c]; dfs(c)
n = int(input())
vals = [0]*(n+1)
for i in range(n): vals[i+1] = int(input())
g,t = {},{}
for i in range(n-1):
    u,v = map(int,input().split())
    g[u] = g.get(u,[])+[v]
    g[v] = g.get(v,[])+[u]
vis = set()
dfs(1)
combos = {}
dp = [[float("inf")]*101 for _ in range(n+1)]
for i in range(2,10001): 
    f = dpf(i)
    combos[f] = min(combos.get(f,float("inf")),i)
def ddp(node):
    f = dpf(vals[node])
    if node in t: 
        for v in t[node]: ddp(v)
    for k in combos.keys():
        ans = combos[k]
        if node in t:
            for v in t[node]:
                m = float("inf")
                for k1 in k: m = min(m,dp[v][k1])
                ans += m
        if f==k: ans -= combos[k]
        for k1 in k: dp[node][k1] = min(dp[node][k1],ans)
ddp(1)
print(min(dp[1]))