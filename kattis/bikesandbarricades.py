n = int(input())
ans = float('inf')
for i in range(n):
    x1,y1,x2,y2 = map(int,input().split())
    if x1>0 and x2>0 or x1<0 and x2<0: continue
    slope = (y2-y1)/(x2-x1)
    if x1>x2:
        x1,x2 = x2,x1
        y1,y2 = y2,y1
    temp = y1-x1*slope
    if temp < 0: continue
    ans = min(ans,y1-x1*slope)
if ans>1e9: print(-1.0)
else: print(ans)