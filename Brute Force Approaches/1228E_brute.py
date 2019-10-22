n = input()

m = n * n
sz = 2 ** m

grid = [[0 for i in xrange(n)] for j in xrange(n)]

ans = 0
for i in xrange(sz):
    for j in xrange(m):
        if (i & (1 << j)):
            grid[j / n][j % n] = 1
        else:
            grid[j / n][j % n] = 0

    flag = 0
    for i in xrange(n):
        if min(grid[i]):
            flag = 1
            break

    for j in xrange(n):
        mn = 2
        for i in xrange(n): mn = min(mn, grid[i][j])
        if mn != 0:
            flag = 1
            break

        if flag: break

    if flag == 0: ans += 1

print ans
            
            
    
    
