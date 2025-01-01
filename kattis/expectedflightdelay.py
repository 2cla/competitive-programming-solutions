a,b,c,d = map(int,input().split())
a-=1
days = {0:'Sunday',1:'Monday',2:'Tuesday',3:'Wednesday',4:'Thursday',5:'Friday',6:'Saturday'}
p,n = 100,(a-1)%7
if n==0 or n==6: p*=(100-c)/100
else: p*=(100-b)/100
ans = 1
while 100-p<d:
    n-=1;n%=7
    ans+=1
    if n==0 or n==6: p*=(100-c)/100
    else: p*=(100-b)/100
if ans==1: print(f'Try to leave on {days[n]}, 1 day before the {days[a]} meeting.')
else:  print(f'Try to leave on {days[n]}, {ans} days before the {days[a]} meeting.')