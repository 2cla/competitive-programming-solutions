def find(i):
    for s in range(1, n+1):
        if state[s] == i: return s

n, m = [int(x) for x in input().split()]
state = [*range(n+2)]
for _ in range(m):
    x, y = [int(x[1:]) for x in input().split()]
    fx, fy = find(x), find(y)
    if fx < fy: continue
    state = state[:fy] + state[fy+1:fx+1] + [y] + state[fx+1:]

print(" ".join(["T" + str(x) for x in state[1:n+1]]))