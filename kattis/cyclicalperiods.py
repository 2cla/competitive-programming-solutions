n = int(input())
lets, pos = {}, {}
for _ in range(n):
    t, l = input().split()
    t = int(t)
    pos[t] = [*l]

for i in range(65537):
    if i in pos:
        for k in range(len(pos[i])):
            if pos[i][k] in lets:
                if lets[pos[i][k]][3]:
                    lets[pos[i][k]] = (i - lets[pos[i][k]][0], i, k, False)
            else:
                lets[pos[i][k]] = (i, _, _, True)

maxlen = 0
maxchar = ("", float("inf"), float("inf"))
for c, (cylen, idx, fidx, _) in lets.items():
    if maxlen < cylen: 
        maxlen, maxchar = cylen, (c, idx, fidx)
    elif maxlen == cylen:
        if idx < maxchar[1]:
            maxchar = (c, idx, fidx)
        elif idx == maxchar[1]:
            if fidx < maxchar[2]:
                maxchar = (c, idx, fidx)

print(maxchar[0])