n = int(input())
matrix = []
for i in range(n):
    temp = input().split(" ")
    tempt = list(map(int, temp[:-1]))
    matrix.append(tempt)
tri = 0
for j in range(n):
    for k in range(j, n):
        if matrix[j][k] == 1:
            for l in range(n):
                if matrix[l][k] == 1 and matrix[l][j] == 1:
                    tri += 1

print(int(tri / 3))