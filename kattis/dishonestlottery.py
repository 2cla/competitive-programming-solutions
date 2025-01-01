n = int(input())
arr = [0]*50
for i in range(10*n):
    nums = map(int,input().split())
    for num in nums: arr[num-1]+=1
ans = []
for i in range(50):
    if arr[i] > 2*n: ans.append(i+1)
if ans: print(" ".join([str(x) for x in ans]))
else: print(-1)