inp = [int(x) for x in input().split()]
n = inp[0]
minarr,maxarr = [1e7]*(n+1),[-1]*(n+1)
ans = []
for i in range(n-1,-1,-1): minarr[i] = min(inp[i+1],minarr[i+1])
for i in range(1,n+1): 
    maxarr[i] = max(inp[i],maxarr[i-1])
    if maxarr[i] == minarr[i-1]: ans.append(str(inp[i]))
m = len(ans)
if m > 100: ans = ans[:100]
print("%d %s"%(m," ".join(ans)))