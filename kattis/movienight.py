import sys; sys.setrecursionlimit(200000)
def ct(cur):
    vis.add(cur)
    st = 1
    ch = bwd.get(cur, [])
    for b in ch: st *= ct(b)
    return (st + 1) % mod

n = int(input())
fwd,bwd = {},{}
for i in range(1,n+1):
    y = int(input())
    fwd[i] = y; 
    if y in bwd: bwd[y].append(i)
    else: bwd[y] = [i]
vis = set()
tot, mod = 1, int(1e9+7)
for i in range(1,n+1):
    if i in vis: continue
    cyc,cur,ctr = {i:0},i,0
    while fwd[cur] not in cyc:
        ctr += 1
        cur = fwd[cur]
        cyc[cur] = ctr
    brnches = []
    cylen = ctr-cyc[fwd[cur]]+1
    cyc = set()
    for _ in range(cylen):
        cyc.add(cur)
        vis.add(cur)
        cur = fwd[cur]
    for _ in range(cylen):
        for b in bwd[cur]: 
            if b not in cyc: brnches.append(b)
        cur = fwd[cur]
    subtot = 1
    for b in brnches:
        subtot *= ct(b) % mod
    tot *= (subtot + 1) % mod
print((tot - 1) % mod)