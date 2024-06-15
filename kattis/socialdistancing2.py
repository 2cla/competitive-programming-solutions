s, n = [int(x) for x in input().split()]
table = [int(x) for x in input().split()]
table.append(s + table[0])
friends = 0
for i in range(n):
    if table[i+1] - table[i] > 2: friends += (table[i+1] - table[i] - 2) // 2
print(friends)