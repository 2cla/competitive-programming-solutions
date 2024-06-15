s = input()
ans = []
for i in range(1,len(s)+1):
    aw,bw = 0,0
    sa,sb = 0,0
    for c in s:
        if c=='A': sa+=1
        else: sb+=1
        if sa<i and sb<i: continue
        if sa==i: aw+=1
        else: bw+=1
        sa,sb = 0,0
    if aw>bw: ans.append(str(i))
print(len(ans))
if ans: print(" ".join(ans))