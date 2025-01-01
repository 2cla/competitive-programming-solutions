import sys
sys.setrecursionlimit(10**6)
n=int(input())
cols,edges,ogedges=[0],{},[]
for _ in range(n):cols.append(int(input()))
for _ in range(n-1):
    u,v=map(int,input().split())
    ogedges.append((u,v))
    if u in edges:edges[u].append(v)
    else:edges[u]=[v]
    if v in edges:edges[v].append(u)
    else:edges[v]=[u]
vis=set()
ans,colcount={},[0]*(n+1)
def rec(u):
    if u in vis:return
    vis.add(u)
    colcount[cols[u]]+=1
    for v in edges[u]:rec(v)
rec(1)
vis=set()
def rec2(u):
    vis.add(u)
    t1,nans={},0
    for v in edges[u]:
        if v in vis:continue
        t2,n2=rec2(v)
        ans[(u,v)]=n2
        if len(t2)>len(t1):t1,t2=t2,t1
        for k in t2.keys():
            nans-=2*t1.get(k,0)*t2[k]
            t1[k]=t1.get(k,0)+t2[k]
        nans+=n2
    nans-=2*t1.get(cols[u],0)
    t1[cols[u]]=t1.get(cols[u],0)+1
    nans+=colcount[cols[u]]-1
    return t1,nans
rec2(1)
for u,v in ogedges:
    if (u,v) in ans:print(ans[(u,v)])
    else:print(ans[(v,u)])