global data 
data = [None] * 200100
lazy = [0] * 200100

def compare(a, b):
    if (a[0] < b[0]):
        return -1 
    if (a[0] > b[0]):
        return 1
    if (a[1] < b[1]):
        return -1
    if (a[1] > b[1]):
        return 1
    return 0

def merge(a, b):
    c = []
    i = 0
    j = 0
    while (i < len(a) and j < len(b)):
        if (compare(a[i], b[j]) == 1):
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    while (i < len(a)):
        c.append(a[i])
        i += 1
    while (j < len(b)):
        c.append(b[j])
        j += 1
    return c

def build(i, lef, rig):
    global data 
    if (lef == rig):
        data[i] = [[0, lef]]
        return 
    mid = (lef + rig) // 2
    build(i * 2, lef, mid)
    build(i * 2 + 1, mid + 1, rig) 
    data[i] = merge(data[i * 2], data[i * 2 + 1])
    while (len(data[i]) > 5):
        data[i].pop()

def update(i, lef, rig, u, v, value):
    global data 
    global lazy 
    if ((rig < u) or (lef > v)):
        return 
    if ((u <= lef) and (rig <= v)):
        lazy[i] += value 
        for j in range(len(data[i])):
            data[i][j] = [data[i][j][0] + value, data[i][j][1]]
        return 
    mid = (lef + rig) // 2
    if (lazy[i] != 0):
        lazy[i * 2] += lazy[i]
        lazy[i * 2 + 1] += lazy[i]
        for j in range(len(data[i * 2])):
            data[i * 2][j] = [data[i * 2][j][0] + lazy[i], data[i * 2][j][1]]
        for j in range(len(data[i * 2 + 1])): 
            data[i * 2 + 1][j] = [data[i * 2 + 1][j][0] + lazy[i], data[i * 2 + 1][j][1]]
        lazy[i] = 0 
    update(i * 2, lef, mid, u, v, value)
    update(i * 2 + 1, mid + 1, rig, u, v, value)
    data[i] = merge(data[i * 2], data[i * 2 + 1])
    while (len(data[i]) > 5):
        data[i].pop()

n, q = [int(i) for i in input().strip().split(' ')]
build(1, 1, n)
for iq in range(q):
    line = input().strip().split(' ')
    if (len(line) == 2):
        k = int(line[1])
        for i in data[1]:
            print(i[1], end= " ")
            k -= 1
            if (k == 0):
                break 
        print()
    else:
        l, r, v = int(line[1]), int(line[2]), int(line[3])
        update(1, 1, n, l, r, v)

