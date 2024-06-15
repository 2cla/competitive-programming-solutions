n, c = [int(x) for x in input().split()]
w = [int(x) for x in input().split()]
s, e  = 0, 0
en, ex = [0]*(n+1), [0]*(n+1)
rs = w[0]
t = 0
while s < n:
    t += 1
    if e + 2 > n:
        rs -= w[s]
        ex[s] = t
        s += 1
    elif rs + w[e+1] > c:
        rs -= w[s]
        ex[s] = t
        s += 1
    else:
        e += 1
        rs += w[e]
        en[e] = t
for i in range(n): print(ex[i] - en[i])