n, w = [int(x) for x in input().split()]
guess, res, poss = [], [], []
for _ in range(n): 
    g, r = input().split()
    guess.append(g)
    res.append(r)
for _ in range(w): poss.append(input())
mask = [True]*w
for idx, p in enumerate(poss):
    for jdx, g in enumerate(guess):
        r = ["a"]*5
        c1, c2 = {}, {}
        for c in p: c1[c] = c1.get(c, 0) + 1
        for c in g: c2[c] = c2.get(c, 0) + 1
        for i in range(5):
            if p[i] == g[i]:
                r[i] = "G"
                c1[p[i]] -= 1
                c2[g[i]] -= 1
            if g[i] not in c1: r[i] = "-"
        for i in range(5):
            if g[i] in c1 and r[i] != "G":
                if c1[g[i]] > 0 and c2[g[i]] > 0: 
                    r[i] = "Y"
                    c1[g[i]] -= 1
                    c2[g[i]] -= 1
                else: r[i] = "-"
        r1 = "".join(r)
        if r1 != res[jdx]: 
            mask[idx] = False
            break
for i, p in enumerate(poss):
    if mask[i]: print(p)