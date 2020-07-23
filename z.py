s   = raw_input()
lis = s.strip().split(" ")
n = (int)(lis[0])
w = (int)(lis[1])
t = (int)(lis[2])
r = (int)(lis[3])

fac = [1 for i in range(301)] 
for i in range(1,301):
	fac[i] = i * fac[i-1]

ans = fac[n]/fac[w];
ans = ans/fac[t];
ans = ans/fac[r];

ans = ans % (1e9+7);
print ans