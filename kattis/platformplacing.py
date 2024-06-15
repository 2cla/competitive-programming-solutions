n, s, k = [int(x) for x in input().split()]
anchs = []
for _ in range(n): anchs.append(2 * int(input()))
anchs.sort()
start, end = [-1e6], [-1e6]
for a in anchs:
    if end[-1] > a - s: print(-1); exit(0)
    start.append(a - s)
    end.append(a + s)
totsum = 0
start.append(3e9); end.append(3e9)
for i in range(n):
    l = min(k, anchs[i]-end[i], start[i+2]-anchs[i])
    totsum += l
    start[i+1] = anchs[i]-l
    end[i+1] = anchs[i]+l
print(totsum)