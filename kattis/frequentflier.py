import heapq
n,m,k = map(int,input().split())
fs = []
for _ in range(n): fs.append(int(input()))
ps = [0]
for f in fs: ps.append(ps[-1]+f)
paids = [0]*n
heap = []
s,e,paid = -m,-1,0
while s<n:
    if s >= 0: paid -= paids[s]
    if e < n-1: heapq.heappush(heap,(-e-1,fs[e+1]))
    s += 1; e += 1
    st,en = max(0,s),min(n-1,e)
    totf = ps[en+1]-ps[st]
    due = min(totf,k)
    while paid < due and heap:
        x = heapq.heappop(heap)
        if -x[0] < st: continue
        if due-paid < x[1]: heapq.heappush(heap,(x[0],x[1]-(due-paid)))
        paids[-x[0]] += min(due-paid,x[1])
        paid += min(due-paid,x[1])
print(sum(paids))