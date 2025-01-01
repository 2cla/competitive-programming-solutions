from math import sqrt
x1,y1,x2,y2,a = map(int,input().split())
mid = (x1+x2)/2
lo,hi = mid-a/2,mid
while hi-lo>1e-4:
    m=(lo+hi)/2
    far = False
    start=min(y1,y2)
    for i in range(abs(y1-y2)*2000+10):
        dx1,dx2 = (m-x1)*(m-x1),(m-x2)*(m-x2)
        if sqrt(dx1+(start-y1)*(start-y1))+sqrt(dx2+(start-y2)*(start-y2))<=a: 
            far=True
            break
        start += 5e-4
    if far:hi=m
    else:lo=m
ans1 = lo
ans3 = ans1+2*(mid-ans1)
mid = (y1+y2)/2
lo,hi = mid-a/2,mid
while hi-lo>1e-4:
    m=(lo+hi)/2
    far = False
    start=min(x1,x2)
    for i in range(abs(x1-x2)*2000+10):
        dy1,dy2 = (m-y1)*(m-y1),(m-y2)*(m-y2)
        if sqrt(dy1+(start-x1)*(start-x1))+sqrt(dy2+(start-x2)*(start-x2))<=a: 
            far=True
            break
        start += 5e-4
    if far:hi=m
    else:lo=m
ans2 = lo
ans4 = ans2+2*(mid-ans2)
print(" ".join([str(x) for x in [ans1,ans2,ans3,ans4]]))