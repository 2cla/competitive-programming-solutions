n, m = [int(x) for x in input().split()]
animals = {}
pens = {}
allgood = True
for i in range(n):
    pendata = input().split()
    pens[pendata[0]] = [0, 0]
    animals[pendata[0]] = animals.get(pendata[0], 0)
    for j in range(int(pendata[1])):
        if pendata[j+2] == pendata[0]:
            pens[pendata[0]][0] += 1
        else: allgood = False
        animals[pendata[j+2]] = animals.get(pendata[j+2], 0) + 1
    pens[pendata[0]][1] = int(pendata[1]) - pens[pendata[0]][0]

fail, key1, key2 = False, False, False
for k, v in pens.items():
    if v[0] + v[1] != animals[k]:
        if v[0] + v[1] + 1 == animals[k]:
            if not key1: key1 = True
            else: fail = True
        elif v[0] + v[1] - 1 == animals[k]:
            if not key2: key2 = True
            else: fail = True
        else: fail = True
print(animals)
if allgood: print("FALSE ALARM")
elif not fail and ((key1 and key2) or (not key1 and not key2)): print("POSSIBLE")
else: print("IMPOSSIBLE")