n = int(input())
lower, upper, checked = [0]*n, [0]*n, [False]*n
for i in range(n):
    l, u = [int(x) for x in input().split()]
    lower[i], upper[i] = l-1, u-1
teams = 0
for k in range(n-2):
    if checked[k]: continue
    if upper[k] >= k+2 and lower[k+2] <= k:
        teams += 1
        checked[k], checked[k+1], checked[k+2] = True, True, True
print(teams)