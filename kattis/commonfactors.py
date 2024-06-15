import math
s = int(input())
p = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53]
a,n,d = 1,1,1
for x in p:
    if a*x > s: break
    a *= x; n *= x-1; d *= x
print("%d/%d" % ((d-n)/math.gcd(n,d),d/math.gcd(n,d)))