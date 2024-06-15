n,p = map(int,input().split())
ps = []
for _ in range(n): ps.append(int(input()))
s = 0
for i in range(n):
    if 1+s+(i+1)*(ps[i]-1)>p: print(i); exit(0)
    s += ps[i]
print(n)