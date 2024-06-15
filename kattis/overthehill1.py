n = int(input())
mat = []
for i in range(n):
    row = [int(x) for x in input().split()]
    mat.append(row)
text = str(input())

c2e, e2c = {" ": 36}, {36: " "}
for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
    c2e[c] = ord(c) - 65
    e2c[ord(c) - 65] = c
for i in range(10):
    c2e[str(i)] = i+26
    e2c[i+26] = str(i)

def matmul(a, x):
    b = [0] * n
    for i in range(n):
        for j in range(n):
            b[i] += a[i][j] * x[j]
    b = [x % 37 for x in b]
    return b

en = []
for c in text: en.append(c2e[c])

vlist = []
while len(en) % n != 0:
    en.append(36)
while en:
    vl = []
    for i in range(n):
        vl.append(en.pop(0))
    vlist.append(vl)

pvlist = []
for vl in vlist:
    pvlist.append(matmul(mat, vl))

s = ""
for pvl in pvlist:
    s += "".join([e2c[pv] for pv in pvl])

print(s)