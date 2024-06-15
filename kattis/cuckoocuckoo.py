h, m = [int(x) for x in input().split(":")]
n = int(input())

if m == 0:
    n -= h
elif m > 45:
    m = 0
    h = (h % 12) + 1
    n -= h
elif m % 15 == 0:
    n -= 1
else:
    m += 15 - (m % 15)
    n -= 1

while n > 0:
    if m == 45:
        m = 0
        h = (h % 12) + 1
        n -= h
    else:
        m += 15
        n -= 1

def f(s):
    if s < 10: return "0" + str(s)
    else: return str(s)

print(":".join([f(s) for s in [h, m]]))