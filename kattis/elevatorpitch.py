from collections import deque
h,w = map(int,input().split())
grid,vis,ans = [],set(),0
for _ in range(h): grid.append([*map(int,input().split())])
for i in range(h):
    for j in range(w):
        if grid[i][j] > 1 and (i,j) not in vis:
            vis2 = set()
            val = True
            stack = deque([(i,j)])
            while stack:
                x,y = stack.popleft()
                if x<0 or x>h-1 or y<0 or y>w-1 or (x,y) in vis2 or grid[x][y] < grid[i][j]: continue
                if grid[x][y] > grid[i][j]: val = False; continue
                vis2.add((x,y))
                for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]: stack.append((x+dx,y+dy))
            if val: ans += 1
            vis.update(vis2)
print(ans)