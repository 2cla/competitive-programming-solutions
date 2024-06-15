rain = input()
m = {"R": 1, "B": -1}
rain = [m[x] for x in rain]
n = len(rain)

counts, c = [0], 0
for r in rain:
    c += r
    counts.append(c)

minmax = []
l, s = -float("inf"), float("inf")
lidx, sidx = -1, -1
for r in range(n+1):
    if counts[r] > l:
        l = counts[r]
        lidx = r
    if counts[r] < s:
        s = counts[r]
        sidx = r
    minmax.append((l, s, lidx, sidx))

best = 0
bidx = []
for i in range(1, n+1):
    if abs(counts[i] - minmax[i][0]) >= best:
        if abs(counts[i] - minmax[i][0]) > best:
            bidx = []
            best = abs(counts[i] - minmax[i][0])
        bidx.append((minmax[i][2], i))
    if abs(counts[i] - minmax[i][1]) >= best:
        if abs(counts[i] - minmax[i][1]) > best:
            bidx = []
            best = abs(counts[i] - minmax[i][1])
        bidx.append((minmax[i][3], i))

bidx.sort(key=lambda x : (x[0], x[1]))        
print(str(bidx[0][0] + 1) + " " + str(bidx[0][1]))