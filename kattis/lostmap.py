import sys
sys.setrecursionlimit(10000)
n = int(input())
roads, dists = [], []
for _ in range(n):
    dists.append([int(x) for x in input().split()])

def split(root, br):
    if not br: return
    mindist, minedge = float("inf"), 0
    for b in br:
        if dists[root][b] < mindist:
            mindist = dists[root][b]
            minedge = b
    roads.append((root, minedge))

    root_br, minedge_br = [], []
    for b in br:
        if b == minedge: continue
        if dists[root][b] < dists[minedge][b]: root_br.append(b)
        else: minedge_br.append(b)
    
    split(root, root_br)
    split(minedge, minedge_br)

split(0, [*range(1, n)])
for k, v in roads:
    print("%d %d" % (k+1, v+1))