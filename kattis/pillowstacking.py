from math import ceil
n,c = map(int,input().split())
soft2 = map(int,input().split())
soft = []
for s in soft2: 
    if s<=c:soft.append(s)
poss = set([0])
for i in range(100000):
    pos = set()
    for s in soft: pos.add(ceil(s/(1<<i)))
    if len(pos)==1 and list(pos)[0]==1: break
    poss2 = set()
    for p in poss:
        for s in pos:
            poss2.add(p+s)
    if c in poss2: print('YES');exit(0)
    poss = poss2
for p in poss:
    if p<=c: print('YES');exit(0)
print('NO')