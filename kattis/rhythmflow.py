n,m = map(int,input().split())
def score(x):
    if x <= 15: return 7
    if x <= 23: return 6
    if x <= 43: return 4
    if x <= 102: return 2
    return 0
ex,ac = [],[]
for i in range(n):
    ex.append(int(input()))
for i in range(m): ac.append(int(input()))
dp = [[0]*(n+1) for _ in range(m+1)]
for i in range(m):
    for j in range(n):
        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j], dp[i][j] + score(abs(ex[j]-ac[i])))
print(dp[-1][-1])