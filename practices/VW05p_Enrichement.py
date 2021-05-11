n, m = [int(i) for i in input().strip().split(' ')]
a = [None] * n 
for i in range(n):
    a[i] = [int(x) for x in input().strip().split(' ')]
ans = int(1e18)
for i in range(n - 2):
    for j in range(m - 2):
        tmp = 0
        for dx in range(3):
            for dy in range(3):
                tmp += a[i + dx][j + dy]
        ans = min(ans, tmp) 
print(ans)  
