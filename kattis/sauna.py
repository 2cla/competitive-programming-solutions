n = int(input())
mins,maxs=[],[]
for i in range(n):
    a,b = map(int,input().split())
    mins.append(a);maxs.append(b)
a1,a2 = max(mins),min(maxs)
if a1>a2: print('bad news')
else: print(f'{a2-a1+1} {a1}')