n, m, q = [int(i) for i in input().strip().split(' ')]
a = [None] * n 
for i in range(n):
    a[i] = input().strip()

s = [set()] * 11 
for i in range(n):
    for j in range(m):
        for t in range(1, 11):
            if (j + t - 1 < m):
                s[t].add(a[i][j:j + t])
            if (i + t - 1 < n):
                s[t].add("".join([a[i + x][j] for x in range(t)]))
            
for i in range(q):
    key = input().strip()
    if (key in s[len(key)]):
        print('1', end="")
    else:
        print('0', end="")

print()