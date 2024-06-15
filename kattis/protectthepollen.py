from collections import deque
n, s = [int(x) for x in input().split()]
bees, poll = [], []
for _ in range(n): 
    a, b = [int(x) for x in input().split()]
    bees.append(a); poll.append(b)
g = {0:[]}
for _ in range(n-1):
    u, v = [int(x)-1 for x in input().split()]
    g[u] = g.get(u, []) + [v]
    g[v] = g.get(v, []) + [u]
d = deque([0])
while d:
    c = d.pop()
    for v in g[c]:
        g[v].remove(c)
        d.append(v)

memo = [[0] + [-float("inf")]*300 for _ in range(n)]
vis = set()

def dp(f):
    if f in vis: return memo[f]
    vis.add(f)
    for v in g[f]:
        sub = dp(v)
        for i in range(s, -1, -1):
            for j in range(i+1):
                memo[f][i] = max(memo[f][i], sub[j] + memo[f][i-j])
    temp = [-float("inf")]*301
    temp[bees[f]] = poll[f]
    for v1 in g[f]:
        for v2 in g[v1]:
            sub = dp(v2)
            for i in range(s, bees[f]-1, -1):
                for j in range(i+1-bees[f]):
                    temp[i] = max(temp[i], sub[j] + temp[i-j])
    for i in range(s+1): memo[f][i] = max(memo[f][i], temp[i])
    return memo[f]

m = dp(0)
print(max(m))