a, b, c = [int(x) for x in input().split()]
inter, fin = [], []
m = float("inf")
inter.append(a+b); inter.append(a-b); inter.append(a*b)
if a % b == 0: inter.append(a/b)
for x in inter:
    fin.append(x+c); fin.append(x-c); fin.append(x*c)
    if x % c == 0: fin.append(x/c)
fin = [int(x) for x in fin]
fin.sort()
for f in fin:
    if f < 0: continue
    print(int(f))
    exit(0)