reg = int(input())
out = 0
regs = [int(x) for x in input().split()]
regs.sort(reverse=True)
for i in range(reg // 2): out += regs[i]
for i in range(reg // 2, reg): out += (regs[i] // 2)
print(out)