import sys; input = sys.stdin.readline
s = [ord(x) for x in input()[:-1]]
dp = [1]*len(s)
for i in range(len(s)):
    for j in range(i):
        if s[i] > s[j]: dp[i] = max(dp[i], dp[j] + 1)
print(26 - max(dp))