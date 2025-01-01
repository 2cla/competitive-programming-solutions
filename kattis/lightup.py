n = int(input())
grid = []
for i in range(n):
    grid.append([*input()])
def checknum(i,j):
    temp = 0
    for dx,dy in [(0,1),(0,-1),(1,0),(-1,0)]:
        if i+dx>=0 and i+dx<n and j+dy>=0 and j+dy<n:
            if grid[i+dx][j+dy]=='?': temp+=1
    return temp==int(grid[i][j])
lit = set()
def inbounds(i,j):
    return i>=0 and i<n and j>=0 and j<n
def checklit(i,j):
    for dx,dy in [(0,1),(0,-1),(1,0),(-1,0)]:
        tx,ty = i,j
        while inbounds(tx,ty):
            if tx==i and ty==j: tx+=dx; ty+=dy; continue
            if grid[tx][ty]=='?': print(0); exit(0)
            elif grid[tx][ty]=='.': lit.add((tx,ty)); tx+=dx; ty+=dy
            else: break
nums = set(['0','1','2','3','4'])
for i in range(n):
    for j in range(n):
        if grid[i][j] in nums:
            if not checknum(i,j): print(0); exit(0)
        if grid[i][j]=='?': checklit(i,j)
for i in range(n):
    for j in range(n):
        if grid[i][j]=='.' and (i,j) not in lit: print(0); exit(0)
print(1)