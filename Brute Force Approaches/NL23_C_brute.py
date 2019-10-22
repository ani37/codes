g = 0

def f(x):
    global g
    
    s = str(x)
    l = map(int, list(s))
    yes1 = yes2 = 1
    for i in xrange(len(l) - 1):
        if l[i] <= l[i + 1]: continue
        else:
            yes1 = 0
            break

    for i in xrange(1, len(l)):
        if l[i] <= l[i - 1]: continue
        else:
            yes2 = 0
            break

    if yes2:
        if l[0] != l[len(l) - 1]:
            g += 1
            #print ''.join(map(str, l))

    yes = (yes1 | yes2)
    return yes

ans = 0
for i in xrange(1, 100000):
    if f(i): ans += 1

#print "g =", g
print ans
