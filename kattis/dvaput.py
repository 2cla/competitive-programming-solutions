l = int(input())
s = input()
a,b = 981264193829604711,915839105244339126
h,p = [ord(s[0])],[1]
for i in range(1,l):
    h.append((h[-1]*a+ord(s[i]))%b); p.append((p[-1]*a)%b)
def search(n):
    hs = set()
    for i in range(l-n+1):
        hsh = (h[i+n-1]-h[i-1]*p[n])%b if i else h[n-1]
        if hsh in hs: return True
        hs.add(hsh)
    return False
lo,hi = 0,l
while hi and lo<hi:
    mid = (lo+hi+1)//2
    if search(mid): lo = mid
    else: hi = mid-1
print(hi)