n,r = map(int,input().split())
arr = sorted([*map(int,input().split())])
tot,ans = 0,[]
for _ in range(45):
    if not arr: continue
    idx,hit,hitx = 0,0,-float("inf")
    for i,v in enumerate(arr):
        left = v-2*r
        while arr[idx] < left: idx += 1
        if i-idx+1 > hit: hit = i-idx+1; hitx = v-r
    arr2 = []
    for a in arr:
        if a < hitx-r or a > hitx+r: arr2.append(a)
    arr = arr2
    tot += 1; ans.append(str(hitx))
print(tot)
print(" ".join(ans))