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
#define cr(P)       cout<<P<<"\n";return;
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)
using namespace std;


const ll N   =  500005;
const ll mod = 1e9 + 7;


vector<ll> adj[N];
vector<ll> color(N);
vector<ll> in(N), out(N);
ll dp[N][20];
ll tim = 0;

void dfs(ll v,ll p=1){

    dp[v][0] = p;
    in[v] = tim++;
    color[v] = 1;
    fr(i,1,20){
     dp[v][i] = dp[dp[v][i-1]][i-1];
    }

    for (ll u : adj[v]){

      if (color[u] == 0){
          dfs(u,v);
      }
    }
    color[v] = 2;
    out[v] = tim++;
}
bool is_ancestor(ll x,ll y) {
  return in[x]<=in[y] and out[x]>=out[y];
}

ll lca(ll u,ll v){

  if(is_ancestor(u,v))
    return u;
  if(is_ancestor(v,u))
    return v;

  for (ll i = 19; i >=0 ; --i){
    if(!is_ancestor(dp[u][i],v))
     u = dp[u][i];
  }
  return dp[u][0]; 
}


void solve(){

  ll n, m, k, x=0, y=0, c=0, q, ans=0;
  cin>>n;

  for (int i = 1; i < n; ++i){
   cin>>x >> y;
   adj[x].pb(y);
   adj[y].pb(x);
  }

  dfs(1);

  cin>>q;
  m=1;
  while(q--){
    c=0;

    cin>> k;
  
    if(k==1){
    cin>>x;
    m = x;
    }

    else if(k==2){ 
      cin>>x>>y;
      ll bet = lca(m,y);
      if(is_ancestor(bet,x) && (is_ancestor(x,m) or is_ancestor(x,y)))
      cout<<"YES\n";
    else cout<<"NO\n";
    }
  }
}

signed main(){
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  //int T;cin >> T;while (T--)
  solve();
  return 0;
}
