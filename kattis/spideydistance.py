import math
t,s = map(int,input().split())
tt,st = 0,0
for i in range(2,s):
    ds = max(0,min(i-1,2*(s-i)))
    tt += max(0,min(i-1,t-i,ds)); st += ds
tt *= 8; st *= 8
tt += 4*min(s,t)+4*min(2*s//3,t//2)+1; st += 4*(5*s//3)+1
if st == tt: print(1); exit(0)
gcd = math.gcd(st,tt)
print("%d/%d"%(tt/gcd,st/gcd))