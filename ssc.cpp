
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
#define mem(a,val)  memset(a, val, sizeof(a))
#define fr(i,x,n)   for(ll i=x; i<n; i++)
#define frr(i,x,n)  for(ll i=n-1; i>=x; i--)
using namespace std;


const ll N   =  1000005;
const ll mod = 1e9 + 7;
ll n, m, k;
vector<ll> adj[N], adjr[N], comps[N];
vector<ll> order, comp;
vector<bool> vis;

void dfs(ll v){
    vis[v] =1;
    for(auto u : adj[v]){
        if(!vis[u])
            dfs(u);
    }
    order.pb(v);
}
void dfs2(ll v,ll c){
    comp[v] =c;
    comps[c].pb(v);
    for(auto u : adjr[v]){
        if(comp[u] == -1)
            dfs2(u,c);
    }
}



void solve(){

    ll x=0, y=0, ans = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        adjr[i].clear();
        comps[i].clear();
    }
    order.clear();
  
    cin >> n >> m;
    for (ll i = 0; i < m; ++i){
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adjr[y].pb(x);
    }

    vis.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, c++);
    }




    // for (int j = 0; j < component.size(); ++j)
    //  {
    //    cout<<component[j]<<" ";
    //  }
    //  c("");
    //  component.clear();
    // }

 
}

signed main(){
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  int T;cin >> T;while (T--)
  solve();
  return 0;
}
