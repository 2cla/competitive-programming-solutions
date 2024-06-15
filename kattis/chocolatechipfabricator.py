from collections import deque
n, m = map(int, input().split())
gr, st = [], deque([])
for _ in range(n): gr.append([*input()])
for i in range(n):
    for j in range(m):
        if gr[i][j] == "X":
            if i in [0, n-1] or j in [0, m-1]: st.append((i, j)); gr[i][j] = "C"
            elif gr[i-1][j] in "XC" and gr[i+1][j] in "XC" and gr[i][j-1] in "XC" and gr[i][j+1] in "XC": continue
            else: st.append((i, j)); gr[i][j] = "C"
ans = 0
while st:
    ans += 1; nst = deque([])
    while st:
        i, j = st.popleft()
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            if i+dx > -1 and i+dx < n and j+dy > -1 and j+dy < m:
                if gr[i+dx][j+dy] == "X": nst.append((i+dx, j+dy)); gr[i+dx][j+dy] = "C"
    st = nst
print(ans)