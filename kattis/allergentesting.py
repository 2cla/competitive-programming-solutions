t = int(input())
for _ in range(t):
    n,d = map(int,input().split())
    for i in range(61):
        if (d+1)**i >= n: print(i); break