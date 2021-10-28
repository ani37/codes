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
 
 
void solve()
{
// string s;
  ll n,m,k,x=0,y=0,c=0,q,ans=0;
  cin>>n>>k;
  ll a[n];
  queue<ll>nodes;
  std::map<ll, ll> mp;
  for (ll i = 0; i < n; ++i)
  {
  cin>>a[i];
  }
  for (int i = 0; i < n; ++i)
  {
    if(mp[a[i]]>0)
    {
      continue;
    }
    if(nodes.size()==k)
    {
      x = nodes.front();
      nodes.pop();
      mp.erase(x);
    }
    nodes.push(a[i]);
    mp[a[i]] =1;
  }
  std::vector<ll> v;
  c(nodes.size());
  while(!nodes.empty())
  {
 v.pb(nodes.front());
  nodes.pop();
  }
  for (int i = v.size()-1; i >= 0; --i)
  {
   cout<<v[i]<<" ";
  }
}
 
signed main(){
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif
      ios_base::sync_with_stdio(false);   
      cin.tie(NULL);
      ll T=1;
      //cin>>T;
      while(T--)
      {
      solve();
      }
      return 0;
    }
