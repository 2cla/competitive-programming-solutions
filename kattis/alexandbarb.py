k,m,n = map(int,input().split())
t = k%(m+n)
print(['Alex','Barb'][t<m])