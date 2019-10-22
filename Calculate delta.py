def findavg():
    n = 0
    s = 0
    while 1:
        try:
            a, b = map(int, raw_input().strip().split())
            x = a + 4 * b
            n += 1
            s += x
            print (s * 1.0) / n
        except:
            print (s * 1.0) / n
            return (s * 1.0) / n

lo = findavg()
print "Taken Low"
hi = findavg()
print "Taken Hi"

print lo
print hi

mid = lo + hi
mid /= 2.0

print mid

r = input()
delta = mid - r
delta /= 4.0

print "Expected rating change", round(delta)
print "With an error of +- 10"
