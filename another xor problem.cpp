#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define endl    '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define mod        1000000007
#define rep(i,a,b)  for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  100005
vi a[N];
ll v[N];
ll dp[N];
bool vis[N]={0};
ll dfs(ll node)
{
  vis[node]=1;
  dp[node-1]=v[node-1];
  for(auto i:a[node])
  if(!vis[i])
  dp[node-1]^=dfs(i);
  return dp[node-1];
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS=1;
//  cin>>TESTS;
  while(TESTS--)
  {
    ll n,u,w;
    cin>>n;
    rep(i,0,n-1)
    {
      cin>>u>>w;
      a[u].pb(w);
      a[w].pb(u);
    }
    ll xr=0,x;
    rep(i,0,n)
    {
      cin>>x;
      v[i]=x;
      xr^=v[i];
    }
    dfs(1);
    ll q;
    cin>>q;
    rep(i,0,q)
    {
      cin>>x;
      cout<<(xr ^ dp[x-1])<<endl;
    }
  }
  return 0;
}