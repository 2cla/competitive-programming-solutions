def join(x,y):
    for a in rs[x]:
        for b in rs[y]:
            if a[0]==b[0] and a[1]+b[1]<=n: rs[x+y].add((a[0],a[1]+b[1]))
            if a[0]==b[1] and a[1]+b[0]<=n: rs[x+y].add((a[0],a[1]+b[0]))
            if a[1]==b[0] and a[0]+b[1]<=n: rs[x+y].add((a[1],a[0]+b[1]))
            if a[1]==b[1] and a[0]+b[0]<=n: rs[x+y].add((a[1],a[0]+b[0]))

rs = [set() for _ in range(16)]
n2 = 0
for i in range(4): 
    x,y = map(int,input().split())
    n2 += x*y
    rs[1<<i].add((x,y))
if int(n2**0.5)*int(n2**0.5) != n2: print(0); exit(0)
n = int(n2**0.5)
for i in [1,2,4,8]:
    for j in [1,2,4,8]:
        if i!=j: join(i,j)
for i in [1,2,4,8]:
    for j in [3,5,9,6,10,12]:
        if (i^j).bit_count() == 3: join(i,j)
for i in [3,5,9,6,10,12]:
    for j in [3,5,9,6,10,12]:
        if i^j==15: join(i,j)
for i in [1,2,4,8]:
    for j in [7,11,13,14]:
        if i^j==15: join(i,j)
print(1) if (n,n) in rs[15] else print(0)