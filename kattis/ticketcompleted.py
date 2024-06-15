def makeset(n):
    par = [*range(n)]
    siz = [1 for _ in range(n)]
    return par, siz

def find(par, i):
    if par[i] == i: return i
    par[i] = find(par, par[i])
    return par[i]

def size(par, siz, i): return siz[find(par, i)]

def union(par, siz, a, b):
    pa, pb = find(par, a), find(par, b)
    if pa == pb: return par, siz
    if siz[pa] <= siz[pb]:
        par[pa] = pb
        siz[pb] += siz[pa]
    else:
        par[pb] = pa
        siz[pa] += siz[pb]
    return par, siz

n, m = [int(x) for x in input().split()]
par, siz = makeset(n)
for _ in range(m):
    a, b = [int(x) - 1 for x in input().split()]
    par, siz = union(par, siz, a, b)
tot = 0
for s in range(n): 
    tot += size(par, siz, s) - 1
print(tot / (n * n - n))