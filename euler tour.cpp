
#include<bits/stdc++.h>
#define ll int
#define pb  push_back
#define eb  emplace_back
#define c(P) cout<<P<<"\n"
#define mp(x,y) make_pair(x,y) 
#define mem(a,val) memset(a,val,sizeof(a))
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n"
const ll N=500005;
const ll mod = 1e9 + 7;

using namespace std;

vector<ll> adj[N];
vector<ll> color(N),euler(N);
vector<ll> time_in(N), time_out(N);
ll dfs_timer = 0;

void dfs(ll v)
{
    euler[dfs_timer] = v;
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (ll u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    euler[dfs_timer] = v;
    time_out[v] = dfs_timer++;
}

void solve()
{
  ll T=1;
  //cin>>T;
  while(T--)
  {
  ll n,m,k,x=0,y=0,c=0,q,ans=0;
  cin>>n;
 // string s;
  ll a[n+1];
  for (ll i = 1; i <= n; ++i)
  {
  cin>>a[i];
  }
  for (int i = 0; i < n-1; ++i)
  {
   cin>>x>>y;
   adj[x].pb(y);
   adj[y].pb(x);
  }
  dfs(1);
 
 cin>>q;
 while(q--)
 {   c=0;
  cin>>k>>x>>y;
  if(k==1)
  {
    a[x] = y; 
  }
  else if(k==2)
  { 
    for (ll i = time_in[x]; i <=time_out[x] ; ++i)
    {      
      if(a[euler[i]]%y==0)
      {
        c++;
      }
    }
    c/=2;
    x = c*(c-1)/2;
    c(x);
  }
 }

 }
}

    int main(){
      #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);   
        cin.tie(NULL);
       solve();
    return 0;
    }
