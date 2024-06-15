r,f = map(int,input().split())
print(['up','down'][(180*f)%(360*r)>90*r and (180*f)%(360*r)<270*r])