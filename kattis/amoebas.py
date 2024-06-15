def bfs(i, j):
    if i < 0 or i > m-1 or j < 0 or j > n-1: return
    if grid[i][j] == ".": return
    grid[i][j] = "."
    for dx, dy in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]:
        bfs(i + dx, j + dy)

m, n = [int(x) for x in input().split()]
grid = []
for _ in range(m):
    grid.append([*input()])

ctr = 0
for i in range(m):
    for j in range(n):
        if grid[i][j] == "#":
            ctr += 1
            bfs(i, j)

print(ctr)