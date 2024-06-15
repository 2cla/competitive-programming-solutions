def build(i):
    if i >= sz: return tree[i]
    _, s1, ld = build(2*i)
    _, s2, rd = build(2*i+1)
    d = {}
    for k, v in ld.items(): d[k] = v
    for k, v in rd.items(): d[k] = d.get(k, 0) + v
    if not d: return tree[i]
    majc, majcct = max(d.items(), key=lambda x: x[1])
    if majcct > (s1+s2)/2: tree[i] = (majc, s1+s2, d)
    else: tree[i] = (False, s1+s2, d)
    return tree[i]

def findmajor(a, b):
    a += sz-1; b += sz-1
    majs = set()
    while a <= b:
        if a % 2 == 1:
            if tree[a][0]: majs.add(tree[a][0])
            a += 1
        if b % 2 == 0:
            if tree[b][0]: majs.add(tree[b][0])
            b -= 1
        a //= 2; b //= 2
    return majs

def findrel(a, b, majs):
    a += sz-1; b += sz-1
    d = {}
    while a <= b:
        if a % 2 == 1:
            for m in majs: 
                if m in tree[a][2]: d[m] = d.get(m, 0) + tree[a][2][m]
            a += 1
        if b % 2 == 0:
            for m in majs:
                if m in tree[b][2]: d[m] = d.get(m, 0) + tree[b][2][m]
            b -= 1
        a //= 2; b //= 2
    return d

n, m = map(int, input().split())
sz = n if n & (n-1) == 0 else (1 << n.bit_length())
tree = [(False, 0, {})]*(2*sz)
for i in range(sz, sz+n):
    ph = input()
    tree[i] = (ph, 1, {ph: 1})
build(1)
for _ in range(m):
    l, r = map(int, input().split())
    maj = findmajor(l, r)
    d = findrel(l, r, maj)
    if not d: print("unusable"); continue
    majc, majcct = max(d.items(), key=lambda x: x[1])
    if majcct > (r-l+1)/2: print("usable")
    else: print("unusable")