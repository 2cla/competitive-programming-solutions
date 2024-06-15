params = input().split()
n, m = int(params[0]), int(params[1])
rungs, output = [], [0]*n
for i in range(m): rungs.append(int(input()))

for i in range(1, n+1):
    num = i
    for r in rungs:
        if r == num: num += 1
        elif r == num - 1: num -= 1
    output[num-1] = i

for num in output: print("%d" % num)