d, a1, a2, v, t = [float(i) for i in input().strip().split(' ')]

ans = -1
lef = 0
rig = v / a1 
for it in range(1000):
    t1 = (lef + rig) / 2
    v1 = a1 * t1 
    s1 = a1 * t1 * t1 / 2
    t2 = v1 / a2 
    s2 = a2 * t2 * t2 / 2 
    s3 = d - s1 - s2 
    t3 = s3 / v1 
    if (t3 < t):
        rig = t1
    else: 
        lef = t1 
        ans = t1 + t2 + t3 
    
print("%.12f" %(ans))