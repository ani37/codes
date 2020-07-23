//dsu
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define sz(a)       (ll)(a.size())
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)
using namespace std;


const ll N   =  100005;
const ll mod = 1e9 + 7;
ll col[N], cnt[N], f[N], subtree[N], big[N], ans[N];
vector<ll> g[N];
multiset<ll> active;

void getsz(ll v, ll p) {
  subtree[v]=1;
  for(auto u:g[v])
  {
    if(u==p)
      continue;
    getsz(u, v);
    subtree[v]+=subtree[u];
  }
}

void add(ll v, ll p, ll x) //Function changes as per question, 
{
  active.erase(cnt[col[v]]);
  f[cnt[col[v]]]-=col[v];
  cnt[col[v]]+=x;
  active.insert(cnt[col[v]]);
  f[cnt[col[v]]]+=col[v];
  for(auto u:g[v])
  {
    if(u!=p && !big[u])
      add(u, v, x);
  }
}

void compute(ll v)
{
  ll maxf=*(--active.end());
  ans[v]=f[maxf];
}

void dfs(ll v, ll p, ll keep){

  ll mx = -1, bigChild = -1;
  for(auto u:g[v]){

    if(u!=p && subtree[u]>mx)
      mx=subtree[u], bigChild=u;
  }
  for(auto u:g[v]){
    if(u!=p && u!=bigChild)
      dfs(u, v, 0); //Run DFS on small children and clear them
  }
  if(bigChild!=-1){
    dfs(bigChild, v, 1);
    big[bigChild]=1;
  }
  add(v, p, 1); 
  //Now we have the information of subtree of v
  compute(v);

  if(bigChild!=-1)
    big[bigChild]=0;
  if(keep==0)
    add(v, p, -1);
}


void solve(){

  ll n,m,k,x,y;
  cin>>n;
  
  for (ll i = 1; i <= n; ++i){

  cin>>col[i];
  }
  for (ll i = 1; i < n; ++i){
   
    cin>>x>>y;
    g[x].pb(y);
    g[y].pb(x);
  }
  getsz(1,0);
  dfs(1,0,0);
  for (ll i = 1; i <=n ; ++i)
  {
    cout<<ans[i]<<" ";
  }
}

signed main(){  
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  //ll T;cin >> T;while (T--)
  solve();
  return 0;
}
