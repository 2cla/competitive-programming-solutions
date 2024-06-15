n,m = map(int,input().split())
s,t = [*map(int,input().split())],[*map(int,input().split())]
s += s
i = 0
while i <= 2*n-m:
    v = True
    for c in range(m):
        if t[c]!=s[i+c]: i += 1; v = False; break
    if v: print(1); exit(0)
i,t = 0,t[::-1]
while i <= 2*n-m:
    v = True
    for c in range(m):
        if t[c]!=s[i+c]: i += 1; v = False; break
    if v: print(1); exit(0)
print(0)