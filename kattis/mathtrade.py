n = int(input())
graph = {}
for _ in range(n):
    _, h, w = input().split()
    graph[h] = w
    if w not in graph: graph[w] = None

maxlen = 1
vis = set()
for k in graph.keys():
    if k in vis: continue
    curr, ctr = k, 0
    while curr:
        if curr in vis: 
            if curr == k: maxlen = max(maxlen, ctr)
            break
        vis.add(curr)
        ctr += 1
        curr = graph[curr]

print(["No trades possible", maxlen][maxlen > 1])