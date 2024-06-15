g, n = [int(x) for x in input().split()]
tasks = []
for _ in range(n):
    tasks.append([int(x) for x in input().split()])
tasks.sort(key = lambda x : x[1])
t, ctr = 0, 0
for task in tasks:
    if task[0] >= t:
        ctr += 1
        t = task[1]
if ctr >= g: print("YES")
else: print("NO")