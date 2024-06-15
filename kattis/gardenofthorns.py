import math
n, r, w, h = [int(x) for x in input().split()]
plants = []
for _ in range(n): plants.append([int(x) for x in input().split()])
ev = 0
for x, y, v in plants:
    inters, area = [], 0
    if h-y < r:
        dx = math.sqrt(r*r-(h-y)*(h-y))
        inters.append(((max(0, x - dx), h), (min(w, x + dx), h)))
        area += abs(inters[-1][0][0] - inters[-1][1][0]) * (h-y)
    if x < r:
        dy = math.sqrt(r*r-x*x)
        inters.append(((0, max(0, y - dy)), (0, min(h, y + dy))))
        area += abs(inters[-1][0][1] - inters[-1][1][1]) * x
    if y < r: 
        dx = math.sqrt(r*r-y*y)
        inters.append(((min(w, x + dx), 0), (max(0, x - dx), 0)))
        area += abs(inters[-1][0][0] - inters[-1][1][0]) * y
    if w-x < r:
        dy = math.sqrt(r*r-(w-x)*(w-x))
        inters.append(((w, min(h, y + dy)), (w, max(0, y - dy))))
        area += abs(inters[-1][0][1] - inters[-1][1][1]) * (w-x)
    totangle = math.tau
    for p1, p2 in inters:
        ap1, ap2 = math.atan2(p1[1] - y, p1[0] - x), math.atan2(p2[1] - y, p2[0] - x)
        diff = ap1 - ap2
        if diff < 0: diff += math.tau
        totangle -= diff
    area += r * r * totangle
    ev += area * v / 2
print(ev / (w * h))