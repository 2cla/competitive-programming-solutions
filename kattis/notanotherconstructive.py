n1,k = map(int,input().split())
s = input()
st = []
for c in s:
    if c in "NAC?": st.append(c)
lst = len(st)
dp = [set() for _ in range(lst+1)]
ans = []
def rec(i,n,na,nac):
    if (n,na,nac) in dp[i]: return
    dp[i].add((n,na,nac))
    if nac>k: return
    if i==lst:
        if nac==k:
            an,idx = "",0
            for c in s:
                if c in "NAC?":
                    if not ans[idx]: an += "N"
                    elif ans[idx]&1: an += "A"
                    else: an += "C"
                    idx += 1
                else: an += c
            print(an); exit(0)
        return
    if nac+380*(lst-i) < k: return
    if st[i]=="N": ans.append(0); rec(i+1,n+1,na,nac)
    elif st[i]=="A": ans.append(1); rec(i+1,n,na+n,nac)
    elif st[i]=="C": ans.append(2); rec(i+1,n,na,nac+na)
    else:
        ans.append(0); rec(i+1,n+1,na,nac); ans.pop()
        ans.append(1); rec(i+1,n,na+n,nac); ans.pop()
        ans.append(2); rec(i+1,n,na,nac+na)
    ans.pop()
rec(0,0,0,0)
print(-1)