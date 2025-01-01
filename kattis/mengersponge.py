l,xn,xd,yn,yd,zn,zd = map(int,input().split())
viol = {}
for sn,sd in [(xn,xd),(yn,yd),(zn,zd)]:
    ctr = 0
    while ctr < l:
        if sn<sd: sn*=3
        if not sn: break
        dig = sn//sd
        ctr += 1
        sn -= dig*sd
        if dig==1 and sn: viol[ctr] = viol.get(ctr,0)+1
for k,v in viol.items():
    if v>1: print(0);exit(0)
print(1)