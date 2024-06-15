s = int(input())
w = []
wn = set()
while len(wn)<4:
    s += s//13+15
    if s%100 not in wn: w.append(((s//10)%10,s%10)); wn.add(s%100)
m = 0
while w:
    x,y = map(int,[*input()])
    md = []
    rem = -1
    for i in range(len(w)):
        wl = abs(x-w[i][0])+abs(y-w[i][1])
        if not wl: rem = i
        else: md.append(wl)
    if rem!=-1: print('You hit a wumpus!'); w.pop(rem)
    if w: print(sorted(md)[0])
    m+=1
print(f'Your score is {m} moves.')