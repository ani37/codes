template T BigMod(T b,T p,T m) {
    T r=1;
    while(p) {
        if(p&1)r=(r*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return r;
}

ll fac[N];



ll nCk(ll n,ll k) {
    return (fac[n]*(( BigMod(fac[k],MD-2,MD)*BigMod(fac[n-k],MD-2,MD) )%MD ))%MD;

}