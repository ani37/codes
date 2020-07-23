//techgig question 1
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"
#define dbg(P)      cout<<P<<" "
#define pii         pair<ll,pair<ll,ll>>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)


const ll mod = 1e18 + 7;

using namespace std;
  ll n,m;
ll a[21][21];

ll dp[1025][1025][21];

ll f(ll mask1,ll mask2,ll idx){

  if(idx== n)
    return 0;

  ll &ans = dp[mask1][mask2][idx];

  if(ans!=-1)
    return ans;

  ans = mod;
  ll last = 0;

  for (ll i = 0; i < m; ++i){
    if((mask1 & (1<<i)) and !(mask2 & (1<<i)) ){
      last=  (1<<i);
      break;
    }
  }

  for (ll i = 0; i < m; ++i){

    if(mask1 & (1<<i) and mask2 & (1<<i))
      continue;
    
    if(mask1 & (1<<i)){
      ans = min(ans,a[i][idx] + 
        f(mask1, mask2, idx+1));
    }
    else{ 
        ans = min(ans,a[i][idx] + 
          f(mask1 | (1<<i), mask2 | last, idx+1));
    }
  }

  
  return ans;
}

void solve()
{

  cin>>n >> m;
  mem(dp,-1);
  for (ll i = 0; i < m; ++i){
    for (ll j = 0; j < n; ++j){
      cin >> a[i][j];
    }
  }
  c(f(0,0,0));
}

signed main(){

  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  solve();
  return 0;
}
