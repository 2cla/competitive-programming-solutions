def build(n):
    par = [*range(n)]
    siz = [1]*n
    return par,siz

def find(a):
    if par[a] == a: return a
    else: 
        par[a] = find(par[a])
        return par[a]

def size(a): return siz[find(a)]

def join(a,b):
    pa,pb = find(a),find(b)
    if pa == pb: return
    if size(pa) > size(pb): par[pb] = pa; siz[pa] += siz[pb]
    else: par[pa] = pb; siz[pb] += siz[pa]

n,m = map(int,input().split())
edges = []
for _ in range(m):
    c,a = map(int,input().split())
    edges.append((0,c,a))
costs = [*map(int,input().split())]
for i in range(1,n+1):
    edges.append((i,i%n+1,costs[i-1]))
par,siz = build(n+1)
edges.sort(key=lambda x:x[2])
ans,added = 0,0
for a,b,c in edges:
    if find(a) == find(b): continue
    join(a,b)
    ans += c; added += 1
    if added == n: break
print(ans)