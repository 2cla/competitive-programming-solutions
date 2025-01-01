def manacher_odd(s):
    n = len(s)
    s = "$" + s + "^"
    p = [0] * (n + 2)
    l, r = 1, 1
    for i in range(1, n + 1):
        p[i] = max(0, min(r - i, p[l + (r - i)]))
        while s[i - p[i]] == s[i + p[i]]:
            p[i] += 1
        if i + p[i] > r:
            l, r = i - p[i], i + p[i]
    return p[1:-1]
def manacher(s):
    t = "#" + "#".join(s) + "#"
    res = manacher_odd(t)
    return res[1:-1]

r,c = map(int,input().split())
maxr,maxc = [set() for _ in range(r)],[set() for _ in range(c)]
grid = [[] for _ in range(r)]
for i in range(r):
    grid[i] = [*input()]
for i in range(r):
    temp = ''.join(grid[i])
    res = [x//2 for x in manacher(temp)]
    for j in range(len(res)):
        if not res[j]: continue
        if j%2: maxr[i].add(((j+1)//2-res[j],(j+1)//2+res[j]-1))
        else: maxr[i].add(((j+1)//2-res[j]+1,(j+1)//2+res[j]-1))
for i in range(c):
    temp = ''.join([grid[j][i] for j in range(r)])
    res = [x//2 for x in manacher(temp)]
    for j in range(len(res)):
        if not res[j]: continue
        if j%2: maxc[i].add(((j+1)//2-res[j],(j+1)//2+res[j]-1))
        else: maxc[i].add(((j+1)//2-res[j]+1,(j+1)//2+res[j]-1))
ans = 0
dpmax = [[0]*c for _ in range(r)]
for j in range(c):
    for i in range(r):
        for mc in maxc[j]:
            a,b = mc[0],mc[1]
            if a<=i<=b: dpmax[i][j]=max(dpmax[i][j],b-a+1)
for i in range(r):
    for mr in maxr[i]:
        a,b = mr[0],mr[1]
        for k in range(a,b+1):
            ans = max(ans,(b-a+1)*dpmax[i][k])
print(ans)