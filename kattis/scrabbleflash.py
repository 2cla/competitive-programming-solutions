def cost(w1, w2):
    s, w = 0, len(w2)
    for j in range(1,len(w1)+1):
        for i in range(j):
            if w2.count(w1[i:j]) > 0:
                s = max(s, j-i)
    return w*(w+1) - s*(s+1)

def tsp(curr, bm, fd):
    if fd == 1:
        if bm == 1:
            dp[curr][bm] = 0
            return 0
        else:
            return float("inf")
    res = float("inf")
    for i in range(n):
        if i != curr and bm & (1 << i):
            res = min(res, tsp(i, bm & (~(1 << curr)), fd-1) + graph[i][curr])
    dp[curr][bm] = res
    return res

u, n = [int(x) for x in input().split()]
words, graph = [], [[float("inf")]*n for _ in range(n)]
for _ in range(n): words.append(input())
for i, w1 in enumerate(words):
    for j, w2 in enumerate(words):
        graph[i][j] = cost(w1, w2)

mw, dp = 1, [[float("inf")]*(1 << n) for _ in range(n)]
for i in range(n):
    _ = tsp(i, (1 << n) - 1, n)
for i in range(n):
    for bm, d in enumerate(dp[i]):
        if d <= 2*u:
            mw = max(mw, bin(bm)[2:].count("1"))
print(mw)