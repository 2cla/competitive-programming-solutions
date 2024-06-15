s = input()[::-1]
if s[0] == "E": print("INVALID"); exit(0)
for i in range(len(s)-1):
    if s[i] == "O" and s[i+1] == "O": print("INVALID"); exit(0)
ans = []
for i in range(1,200):
    st = 1<<i
    valid = True
    for c in s:
        if c == "O":
            if (st-1) % 3 != 0: valid = False; break
            st = (st-1) // 3
        if c == "E":
            st *= 2
        if not st & (st-1) or st < 1: valid = False; break
    if valid: ans.append(st)
if len(ans) == 0: print("INVALID"); exit(0)
else: print(sorted(ans)[0])