n = int(input())
s = [*range(1024)]
mgc = [0]
used = set([0])

for i in range(1,1024):
    minval = 2000
    for j in range(1,1024):
        if bin(mgc[-1] ^ j).count("1") % 2 == 0 and j not in used:
            minval = min(minval, j)
    mgc.append(minval)
    used.add(minval)
for _ in range(n):
    idx = int(input())
    print(bin(1024 + mgc[idx])[3:])