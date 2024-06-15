n = int(input())
if n < 10: print(n-1,n+1); exit(0)
imp = True
avail = set()
s = str(n)
for i in range(1,10): 
    if s.count(str(i)) == 0: imp = False; avail.add(i)
if imp:
    if s.count("0") == 0: print(0)
    else: print("Impossible")
    exit(0)
if s.count("0") == 0: avail.add(0)
small,big = "",""
smallt,bigt = False,False
for i in range(int(s[0])+1,10):
    if i in avail:
        big += str(i); bigt = True
        for j in range(1,len(s)): big += str(min(avail))
        break
for i in range(int(s[0])-1,0,-1):
    if i in avail:
        small += str(i); smallt = True
        for j in range(1,len(s)): small += str(max(avail))
        break
if not bigt:
    if not min(avail):
        avail.remove(0)
        big += str(min(avail))
        avail.add(0)
    else: big += str(min(avail))
    for j in range(len(s)): big += str(min(avail))
if not smallt:
    small += str(max(avail))
    for j in range(2,len(s)): small += str(max(avail))
if abs(int(small)-n) == abs(int(big)-n): print(small,big)
elif abs(int(small)-n) < abs(int(big)-n): print(small)
else: print(big)