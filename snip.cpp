//strings
 string to integer stuuu()
 string to long long stoll()
 string.substr(position,length);
 integer to string to_string();

// vector unique
  v.resize(distance(v.begin(), unique(v.begin(), v.end()) ));


//pairs
   bool cmp(const pii &a,const pii &b){ 
      if(a.F==a.F)
        return (a.S < b.S);
      return (a.F < b.F);
    }
  
// fac
ll fac[N],ifac[N];
void pre(){
  fac[0] = 1;
  fr(i,1,N) fac[i] = (fac[i-1] * i) % mod;
  ifac[N-1] = power(fac[N-1],mod-2);
 for(ll i=N-2;i>=0;i--) {
    ifac[i] = (ifac[i+1] * (i+1)) % mod;
  }
}
ll ncr(ll n,ll r){
   if(r>n || r<0) return 0;
  return fac[n]*ifac[n-r]%mod*ifac[r]%mod;
}
// com
ll ncr[N][N];
ll pre() { 
  for (i = 0; i < N; i++){ 
    for (j = 0; j <= i; j++) { 
        
        if (j == 0 || j == i) // Base Cases 
            ncr[i][j] = 1;   
         else 
          ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j]; 
        } 
    } 
  
} 

// function inside main
std::function<void(ll,ll)> dfs = [&](ll i,ll p){

    for(auto& x: adj[i] ){
         if(i== p)continue;
         if(!vis[x]){
             vis[x] = 1;
            col[x] = col[i]^1;
            dfs(x,p);
         }
         if(vis[x] and col[x] == col[i]) {
            f = 0;
            return;
         }
    } 
};


