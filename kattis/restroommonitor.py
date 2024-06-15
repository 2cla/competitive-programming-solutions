s, n = [int(x) for x in input().split()]
tp, notp = [], []
for _ in range(n):
    x, y = input().split()
    if y == "y": tp.append(int(x))
    else: notp.append(int(x))

tpstall = set()
if tp:
    tp.sort(reverse=True)
    ctr = max(tp)
    for t in tp:
        if ctr == 0: 
            print("No")
            exit(0)
        if ctr > t: ctr = t
        while ctr in tpstall: ctr -= 1
        if ctr == 0: 
            print("No")
            exit(0)
        tpstall.add(ctr)
        ctr -= 1
        
notp.sort(reverse=True)
curr = 1
while notp:
    st = s - (curr in tpstall)
    for _ in range(st):
        if not notp:
            print("Yes")
            exit(0)
        p = notp.pop()
        if p < curr:
            print("No")
            exit(0)
    curr += 1
print("Yes")