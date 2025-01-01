from math import ceil
a,b = map(int,input().split())
ans = 0
for i,j in [(a*750,b*1125),(b*750,a*1125)]:
    for par in range(2):
        tpar = par
        tans = 0
        for y in range(750,i+1,750):
            x = int((j*i - j*y)/i)
            if tpar:
                if x>=1125:x-=1125
                tans += x//2250
            else: tans += x//2250
            tpar = 1-tpar
        ans = max(tans,ans)
print(ans)