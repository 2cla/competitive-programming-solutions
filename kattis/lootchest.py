dl, dw, g, l = [int(x) for x in input().split()]
ew = 0
p = [[0]*101 for _ in range(101)]
p[0][0] = 1
for i in range(100):
    for j in range(101):
        p[i+1][min(100,j+dl)] += l * p[i][j] / 100
        p[i+1][min(100,j+dw)] += (100-l) * p[i][j] * (100-j) / 10000
for i in range(1,100):
    for j in range(101):
        ew += (i+1) * j * (100 - l) * p[i][j] / 10000
ew += (100 + 100 / (100 - l)) * p[-1][-1]
print((100 / g) * ew)