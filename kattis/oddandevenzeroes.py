off,on = [1],[0]
for i in range(1,29):
    if i%2: off.append(off[-1]*5); on.append(5**i-off[-1])
    else: off.append(off[-1]*3+on[-1]*2); on.append(5**i-off[-1])
while True:
    n = int(input())+1
    if not n: break
    ans,par = 0,0
    for i in range(28,-1,-1):
        v = n//(5**i)
        for _ in range(v):
            if par%2: ans+=on[i]
            else: ans+=off[i]
            if i%2: par+=1
        n -= v*(5**i)
    print(ans)