def build(tree):
    k = 2
    while k<=nl:
        for i in range(k,nl+1,k):
            tree[i] += tree[i-k//2]
        k *= 2

def sum(tree,k):
    s = 0
    while k>=1:
        s += tree[k]
        k -= k&-k
    return s

def add(tree,k,v):
    while k<=nl:
        tree[k] += v
        k += k&-k

import functools
n,x = map(int,input().split())
pts,d = [],{}
for i in range(n): pts.append(tuple(int(x) for x in input().split()+[i]))
pts2 = sorted(pts,key=functools.cmp_to_key(lambda y,w: (w[0]-x)*y[1]-w[1]*(y[0]-x)))
pts3 = sorted(pts,key=functools.cmp_to_key(lambda y,w: w[0]*y[1]-w[1]*y[0]))
for i in range(n): d[pts3[i][3]] = i+1
nl = n if not n&(n-1) else 1 << n.bit_length()
tree = [0]+[x[2] for x in pts3]+[0]*(nl-n)
build(tree)
ans = [0]*n
for a,b,v,i in pts2:
    add(tree,d[i],-v)
    ans[i] = str(sum(tree,d[i]))
print("\n".join(ans))