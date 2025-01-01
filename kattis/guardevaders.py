from collections import deque
g,p = map(int,input().split())
start = input()
vis = set()
queue = deque([(start,p)])
while queue:
    s,t = queue.popleft()
    if (s,t) in vis: continue
    vis.add((s,t))
    if not t: print('1');exit(0)
    for i in range(g-1):
        if s[i]=='R' or s[i+1]=='L': continue
        scop = [*s]
        scop[i]='R';scop[i+1]='L'
        queue.append((''.join(scop),t-1))
print(0)