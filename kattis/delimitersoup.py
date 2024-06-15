l = int(input())
s = input()
stack = []
pos = 0
d = {")": "(", "]" : "[", "}" : "{"}
ok = True
for c in s:
    if c in d.keys():
        if len(stack) == 0 or d[c] != stack.pop(-1):
            print(c, pos)
            ok = False
            break
    elif c != " ":
        stack.append(c)
    pos += 1
if ok: print("ok so far")