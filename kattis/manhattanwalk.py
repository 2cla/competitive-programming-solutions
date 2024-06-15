from collections import deque
r,c,p = map(int,input().split())
g = [[0]*c for _ in range(r)]
s = deque([(0,0)])
vis = set()
while s:
    x,y = s.popleft()
    if (x,y) in vis: continue
    vis.add((x,y))
    if x<r-1: s.append((x+1,y))
    if y<c-1: s.append((x,y+1))
    if x and y: 
        a,b = g[x-1][y],g[x][y-1]
        su = min(p,abs(a-b))/p
        if a<b: g[x][y] = 0.5*a + 0.5*(1-su)*b + 0.5*su*(a+su*p/2)
        else: g[x][y] = 0.5*b + 0.5*(1-su)*a + 0.5*su*(b+su*p/2)
    elif not x and not y: g[0][0] = 0
    elif not x: g[0][y] = g[0][y-1]+p/4
    else: g[x][0] = g[x-1][0]+p/4
print(g[-1][-1])