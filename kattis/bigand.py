from heapq import heappush as pu, heappop as po
n,d,l = map(int,input().split())
nums = map(int,input().split())
heap = []
for num in nums: pu(heap,num)
while len(heap)>1:
    a = po(heap);b =po(heap)
    pu(heap,max(a,b)+d)
print(heap[0]+l)