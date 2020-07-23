def power(x, y) : 
    res = 1     # Initialize result 
 
    # Update x if it is more 
    # than or equal to p 
 
    while (y > 0) : 
 
        # If y is odd, multiply 
        # x with result 
        if ((y & 1) == 1) : 
            res = (res * x) 
 
        # y must be even now 
        y = y >> 1      # y = y/2 
        x = (x * x)
 
    return res
for _ in xrange(input()):
    n, k = map(int, raw_input().strip().split())
    x=0
    c=0
    if(k==1):
        if(n%2): print ("Alice\n")
        else: print ("Bob\n")
 
    else:
        while 1:    
            if(n-power(k,x)<0):
                c=1 
                break
            n-=power(k,x)
            if(n-power(k,x)<0):
                c=0
                break
            n-=power(k,x)
            x+=1
            
        if(c==1): print "Bob\n"
        else: print "Alice\n"