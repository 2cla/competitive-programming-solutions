d = [[]]*3
for i in range(3): d[i] = [*map(int,input().split())]
def comp(i,j):
    a,b = d[i],d[j]
    n,de = 0,0
    for k in a:
        for v in b:
            if k==v: continue
            de+=1
            if k>v: n+=1
    if de and 2*n>=de: return True
    return False
for i in [0,1,2]:
    ans = True
    for j in [0,1,2]:
        if i!=j: ans &= comp(i,j) 
    if ans: print(i+1); exit(0)
print('No dice')