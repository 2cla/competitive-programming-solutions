n = int(input())
regions = [int(x) for x in input().split()]
regions.sort(reverse=True)
tot = 0
for i in range(n // 2): tot += regions[i]
for j in range(n // 2, n): tot += regions[j] // 2
print(tot)