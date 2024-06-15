n = int(input())
dp = [1e9]*5000001; dp[0]=0
for i in range(n):
    dp2 = [1e9]*5000001
    a,b = map(int,input().split())
    for j in range(100000*i+1):
        dp2[j] = min(dp2[j],dp[j]+b); dp2[j+a] = min(dp2[j+a],dp[j])
    dp = dp2
ans = 1e9
for k,v in enumerate(dp): ans = min(ans,max(k,v))
print(ans)