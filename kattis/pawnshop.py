n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
d, divs = {}, set()
for i in range(n):
    d[a[i]] = d.get(a[i], 0) + 1
    d[b[i]] = d.get(b[i], 0) - 1
    if a[i] in d and d[a[i]] == 0: d.pop(a[i])
    if b[i] in d and d[b[i]] == 0: d.pop(b[i])
    if not d: divs.add(i)
res = []
for j in range(n):
    res.append(b[j])
    if j in divs: res.append("#")
print(" ".join([str(x) for x in res[:-1]]))