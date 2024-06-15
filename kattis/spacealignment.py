n = int(input())
cs,ans,d = [],0,0
for _ in range(n):
    i = input()
    if i[-1]=="}": d-=1
    s,t = i.count("s"),i.count("t")
    if not d and (s or t): print(-1); exit(0)
    cs.append((d,s,t))
    if i[-1]=="{": d+=1
for i in range(n):
    for j in range(i+1,n):
        d1,s1,t1 = cs[i]
        d2,s2,t2 = cs[j]
        s1*=d2;t1*=d2;s2*=d1;t2*=d1
        if t1==t2:
            if s1!=s2: print(-1); exit(0)
        else:
            if (s1-s2)%(t2-t1): print(-1); exit(0)
            pans = (s1-s2)//(t2-t1)
            if pans<1 or (ans and pans!=ans): print(-1); exit(0)
            ans = pans
print(ans) if ans else print(1)