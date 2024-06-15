t = int(input())
for _ in range(t):
    s = input()
    ans = []
    for i in range(1,6):
        if len(s) < i: continue
        ognum = int(s[:i])
        idx,num,miss = 0,int(s[:i]),0
        missing = False
        while len(s) >= idx+len(str(num)):
            if str(num) != s[idx:idx+len(str(num))+1]:
                if miss == 0 and s[idx:idx+len(str(num+1))] == str(num+1): missing = num; num += 1; miss = 1
                else: miss = 2; break
            idx += len(str(num))
            num += 1
        if miss == 2: continue
        if len(s) == idx:
            if miss == 1: ans.append(str(missing))
            if not miss:
                if ognum > 1: ans.append(str(ognum-1))
                if num < 100000: ans.append(str(num))
    print("%d\n%s" % (len(ans)," ".join(ans)))