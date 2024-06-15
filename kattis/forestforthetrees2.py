nt,ns,rm = map(int,input().split())
real,sense,reald = [],[],{}
for _ in range(nt): 
    x,y = map(int,input().split())
    real.append((x,y)); reald[(x,y)] = reald.get((x,y),0)+1
for _ in range(ns): sense.append(tuple(map(int,input().split())))
senserot = [[(x,y),(-y,x),(-x,-y),(y,-x)] for x,y in sense]
found,loc = 0,0
for x,y in sense: 
    if (x,y) == (0,0): print("Impossible"); exit(0)
for x,y in real:
    for i in range(4):
        robot = (x-senserot[0][i][0],y-senserot[0][i][1])
        valid = True
        track = {}
        for j in range(1,ns):
            dx,dy = robot[0]+senserot[j][i][0],robot[1]+senserot[j][i][1]
            if (dx,dy) not in reald: valid = False; break
            else:
                track[(dx,dy)] = track.get((dx,dy),0)+1
                if track[(dx,dy)] > reald[(dx,dy)]: valid = False; break
        if valid:
            count = 0
            for wx,wy in real:
                if abs(robot[0]-wx)+abs(robot[1]-wy) <= rm: count += 1
                if count > ns: valid = False; break
        if valid:
            if found: print("Ambiguous"); exit(0)
            else: found = 1; loc = robot
print(loc[0],loc[1]) if found else print("Impossible")