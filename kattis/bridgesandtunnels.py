def make_set(n):
    parents = list(range(n))
    sizes = [1 for _ in range(n)]
    return parents, sizes

def find(parents, i):
    if parents[i] == i:
        return i
    parents[i] = find(parents, parents[i])
    return parents[i]

def get_size(parents, sizes, i):
    return sizes[find(parents, i)]

def union(parents, sizes, a, b):
    pa = find(parents, a)
    pb = find(parents, b)
    if pa == pb:
        return
    if sizes[pa] <= sizes[pb]:
        parents[pa] = pb
        sizes[pb] += sizes[pa]
    elif sizes[pa] > sizes[pb]:
        parents[pb] = pa
        sizes[pa] += sizes[pb]

count = int(input())
edges = []
buildings = {}
id = -1
for i in range(count): 
    x = input().split()
    edges.append(x)
    if (buildings.get(x[0], -1) == -1):
        id += 1
        buildings[x[0]] = id
    if (buildings.get(x[1], -1) == -1):
        id += 1
        buildings[x[1]] = id
n = len(buildings)
parents, sizes = make_set(n)
for edge in edges:
    union(parents, sizes, buildings[edge[0]], buildings[edge[1]])
    print(get_size(parents, sizes, buildings[edge[0]]))