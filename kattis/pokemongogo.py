def fun(i, mask, idx):
    if idx >= sp - 1:
        return edgemat[0][i]
 
    if memo[i][mask] != -1:
        return memo[i][mask]
    
    res = float("inf")
    for j in relevant:
        if (mask & (1 << j)) != 0 and j != i and j != 0:
            res = min(res, fun(j, mask & (~(1 << j)), idx + 1) + edgemat[j][i])

    memo[i][mask] = res

    return res

import itertools
n = int(input())
pokemon = {" ": [(0, 0, 0)]}
poke_by_id = [(0, 0)]
for i in range(n):
    s = input().split()
    pokemon[s[2]] = pokemon.get(s[2], []) + [(int(s[0]), int(s[1]), i+1)]
    poke_by_id.append((int(s[0]), int(s[1])))

dupes = []
for k, v in pokemon.items():
    dupes.append(v)
combos = list(itertools.product(*dupes))

if combos:
    memo = [[-1]*(1 << (n+1)) for _ in range(n+1)]
    sp = len(combos[0])
    edgemat = [[0]*(n+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(i):
            edgemat[i][j] = abs(poke_by_id[i][0] - poke_by_id[j][0]) + abs(poke_by_id[i][1] - poke_by_id[j][1])
            edgemat[j][i] = edgemat[i][j]

mindist = float("inf")
for combo in combos:
    relevant = [stop[2] for stop in combo]
    bitstring = 0
    for r in relevant[1:]:
        bitstring += 1 << r

    ans = float("inf")
    for i in relevant[1:]:
        ans = min(ans, fun(i, bitstring & (~(1 << i)), 1) + edgemat[i][0])

    mindist = min(ans, mindist)

print(mindist)