import sys
from collections import defaultdict
sys.setrecursionlimit(400000)
MOD=998244353
t=int(input())
def solve():
    n=int(input())
    g=defaultdict(list)
    for _ in range(n-1):
        u,v=map(int,input().split())
        g[u].append(v)
        g[v].append(u)
    vis=[0]*(n+1)
    ans=0
    def rec(u):
        vis[u]=1
        if len(g[u])==1 and vis[g[u][0]]:return 2
        tp1,tp2=1,0
        for v in g[u]:
            if not vis[v]:
                tem=rec(v)
                tp1*=tem
                tp1%=MOD
                tp2+=tem-1
        nonlocal ans
        ans+=tp2
        return tp1+1
    tp=rec(1)
    ans+=tp
    print(ans%MOD)
for _ in range(t):solve()