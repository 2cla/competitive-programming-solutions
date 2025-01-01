a,b = map(int,input().split())
g = {'a':set()}
length,ants = {},{}
for _ in range(a):
    l = input().split()
    n = int(l[0])
    nodes = ['a']
    for j in range(4,4*n+1,4): nodes.append(l[j])
    for j in range(1,4*n+1,4):
        if nodes[(j-1)//4] in g: g[nodes[(j-1)//4]].add(nodes[(j+3)//4])
        else: g[nodes[(j-1)//4]] = set([nodes[(j+3)//4]])
        length[(nodes[(j-1)//4],nodes[(j+3)//4])] = int(l[j+1])
        ants[(nodes[(j-1)//4],nodes[(j+3)//4])] = int(l[j+2])
paths = []
def rec(node,temp):
    if node not in g or not g[node]:
        paths.extend([t+node for t in temp])
    else:
        newtemp = [t+node for t in temp]
        for n in g[node]: rec(n,newtemp)

def get_ants(path,change=False):
    temp=0
    tongue = 30
    for a in range(len(path)-1):
        char = path[a];chari=path[a+1]
        temp+=ants[(char,chari)]
        if change:ants[(char,chari)]=0
        tongue-=length[(char,chari)]
        if tongue<=0: return temp
    return temp
rec('a',[''])
b = min(b,len(paths))
ans = 0
for i in range(b):
    temp = 0
    best = ''
    for p in paths:
        asfas = get_ants(p)
        if asfas >= temp:
            temp = asfas
            best = p
    ans += get_ants(best,True)
print(ans)
    