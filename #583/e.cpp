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
std::vector<ll> adj[N];
std::vector<pii> edges;
std::vector<ll> dis(N);
mi edis;
  pii a[N];  
void solve()
{
// string s;
  ll n,m,k,x=0,y=0,c=0,q,ans=0;
  cin>>n;
  for (int i = 1; i <=n; i++)
  {
      cin>>x;
      a[i].F = x;
      a[i].S = 2*i-1;
  }
  sort(a+1,a+n+1,greater<pii>());
//  edis[0] = a[1].S-1;
  //dis[a[0].S-1] = 0;
  for (int i = 1; i < n; i++)
  {
   edges.pb({a[i].S,a[i+1].S});
  }
  x = n;
 
  for (ll i = 1; i <=n; i++)
  {
  edges.pb({a[i].second+1, a[i + a[i].first - 1].second});
  if (i + a[i].first - 1 == x) {
      a[++x] = {0, a[i].second+1 };
    }
  } 
  for (auto i :edges)
  {
   cout<<i.F<<" "<<i.S<<'\n';
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
