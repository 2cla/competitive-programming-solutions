k,n = map(int,input().split())
we = [*map(int,input().split())]
if k==1: print("YES"); exit(0)
st = set()
we.extend(we)
ps = [0]
for w in we: ps.append(ps[-1]+w)
if ps[n]%k: print("NO"); exit(0)
ta = ps[n]//k
for i in range(n):
    if ps[i] < ta: st.add(i-1)
    else: break
s,e,tot = 0,-1,0
co = len(st)
while e < n+co-1:
    if tot < ta: e += 1; tot += we[e]
    while tot >= ta:
        if tot == ta:
            if s-1 in st: st.add(e); st.remove(s-1)
        tot -= we[s]; s += 1
for i in range(n-1,n+co):
    if i in st: print("YES"); exit(0)
print("NO")