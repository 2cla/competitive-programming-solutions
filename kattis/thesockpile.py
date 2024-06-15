def rec(x,y,z):
    if (x,y,z) in dp: return dp[(x,y,z)]
    if y==0 and z<=1: dp[(x,y,z)] = 1; return 1
    if x<0 or y<0 or z<0: dp[(x,y,z)] = 0; return 0
    d = (x+y+z)*(x+y+z-1)
    dp[(x,y,z)] = (x*(x-1)*rec(x-2,y,z) + 2*x*y*rec(x,y-2,z) + 2*x*z*rec(x-1,y,z-1) + 2*y*z*rec(x+1,y-2,z-1) + y*(y-2)*rec(x+2,y-4,z))/d
    return dp[(x,y,z)]
import time
m,n = map(int,input().split())
a = time.time()
dp = {}
print(rec(0,2*m,n))
print(time.time()-a)