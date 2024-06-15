def move(i, j, dots, ateDot):
    if maze[i][j] == '.':
        dots -= 1
        ateDot = True

    maze[i][j] = 'Y'
    if i > 0:
        if maze[i-1][j] > "9" and maze[i-1][j] < "Z":
            pass
        else: 
            dots, ateDot = move(i-1, j, dots, ateDot)
    if i < n-1:
        if maze[i+1][j] > "9" and maze[i+1][j] < "Z":
            pass
        else: 
            dots, ateDot = move(i+1, j, dots, ateDot)
    if j > 0:
        if maze[i][j-1] > "9" and maze[i][j-1] < "Z":
            pass
        else: 
            dots, ateDot = move(i, j-1, dots, ateDot)
    if j < m-1:
        if maze[i][j+1] > "9" and maze[i][j+1] < "Z":
            pass
        else: 
            dots, ateDot = move(i, j+1, dots, ateDot)
    return dots, ateDot

params = input().split()
n, m = int(params[0]), int(params[1])
maze = [[0]*m]*n
for i in range(n): maze[i] = [x for x in input()]
dots = len([x for y in maze for x in y if x == '.'])
minEntr = 0
print(maze[1])
for i in range(n):
    for j in range(m):
        if maze[i][j] > "9" and maze[i][j] < "X":
            ateDot = False
            dots, ateDot = move(i, j, dots, ateDot)
            if ateDot: minEntr += 1

print("%d %d" % (minEntr, dots))