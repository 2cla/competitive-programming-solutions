import functools
n = int(input())
mags = []
for _ in range(n): mags.append(input())
for i, m in enumerate(mags):
    valid = True
    for c in m:
        if c not in "01869": valid = False; break
    if valid:
        w = [*m[::-1]]
        for j,c in enumerate(w):
            if c == "6": w[j] = "9"
            elif c == "9": w[j] = "6"
        w = "".join(w)
        if w < m: mags[i] = w
print("".join(sorted(mags, key=functools.cmp_to_key(lambda x,y: (x+y>y+x)-(x+y<y+x)))))