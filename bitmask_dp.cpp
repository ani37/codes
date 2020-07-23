
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"
#define dbg(P)      cout<<P<<" "
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)


const ll N   =  500005;
const ll mod = 1e9 + 7;

using namespace std;
  ll n,k;
std::vector<ll> v[105];
ll dp[1025][105];
ll stoi(string &s){
    stringstream ss(s);
    ll x;
    ss>>x;
    return x;
}
ll f(ll mask,ll id)
{
  if(mask== ((1<<n) - 1))
    return 1;
  if(id==101)
    return 0;
  if(dp[mask][id]!=-1)
    return dp[mask][id];
  ll ans = 0;
  //not alloted to anyone
  ans = f(mask,id+1);
  // allot the current tshirt to someone without tshirt
  for(ll i : v[id])
  {
    if(((1<<i)&mask)==0)
      ans+=f(mask|(1<<i),id+1);
  }
  ans%=mod;
return dp[mask][id] = ans;
}
void solve()
{
// string s;
  cin>>n;
  fr(i,0,1025)fr(j,0,102)dp[i][j] = -1;
  for (ll i = 0; i < 105; ++i)
  {
    v[i].clear();
  }
  string s;
   cin.get();
  for (ll i = 0; i < n; ++i)
  {    
      getline(cin,s);

      stringstream ss(s);
      string temp;
      while(ss>>temp)
      {
        v[stoi(temp)].pb(i);
      }
  }
  for (ll i = 0; i < 101; ++i)
  {
    sort(v[i].begin(), v[i].end());
  
  }
  cout<<f(0LL,1LL)<<"\n";
}

signed main(){

      ios_base::sync_with_stdio(false);   
      cin.tie(NULL);
      ll T=1;
      cin>>T;
      while(T--)
      {
      solve();
      }
      return 0;
    }
