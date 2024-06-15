inlist = input().split()
n, m = int(inlist[0]), int(inlist[1])
friends = [0] * n
for i in range(m):
    inlist = input().split()
    a, b = int(inlist[0]), int(inlist[1])
    friends[a-1] += 1
    friends[b-1] += 1

for j in range(n):
    friends[j] -= j + 1
    friends[j] = str(friends[j])

print(" ".join(friends))