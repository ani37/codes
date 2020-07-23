
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define eb          emplace_back
#define c(P)        cout<<P<<"\n"
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define mp(x,y)     make_pair(x,y) 
#define exit(x)     cout<<x<<"\n",return
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,a,n)   for(ll i=a;i<n;i++)
const ll N=500005;
const ll mod = 1e9 + 7;
using namespace std;

class RMQ
{
public:
    RMQ(vector<ll> v) 
    {
        log_table.assign(v.size() + 1, 0);
        for (ll i = 2; i < log_table.size(); i++) 
            log_table[i] = log_table[i/2] + 1;

        sparse_table.assign(log_table.back() + 1, vector<ll>(v.size()));
        sparse_table[0] = v;
        for (ll row = 1; row < sparse_table.size(); row++) {
            for (ll i = 0; i + (1 << row) <= v.size(); i++) {
                sparse_table[row][i] = min(sparse_table[row-1][i], sparse_table[row-1][i+(1<<(row-1))]);
            }
        }
    }

    ll minimum(ll l, ll r) {
        ll lg = log_table[r - l];
        return min(sparse_table[lg][l], sparse_table[lg][r - (1 << lg)]);
    }

private:
    vector<ll> log_table;
    vector<vector<ll>> sparse_table;
};

vector<vector<ll>> adj;
vector<ll> euler_tour;
vector<ll> first_encounter;
vector<ll> new_to_old;

void dfs_euler_tour(ll v, ll p) {
    ll new_index = new_to_old.size();
    new_to_old.push_back(v);
    first_encounter[v] = euler_tour.size();
    euler_tour.push_back(new_index);

    for (ll u : adj[v]) {
        if (u == p)
            continue;

        dfs_euler_tour(u, v);
        euler_tour.push_back(new_index);
    }
}

void solve() {
  ll T;
  cin>>T;
  for (ll test = 1; test <= T; ++test)
  {
    adj.clear();
    euler_tour.clear();
    new_to_old.clear();
    first_encounter.clear();
    ll nodes,x;
   // vector<pair<ll, ll>> edges = {{0, 5}, {5, 7}, {7, 2}, {5, 1}, {1, 3}, {1, 6}, {5, 8}, {0, 9}, {9, 4}};
      cin>>nodes;
    adj.resize(nodes);
    for (ll i = 0; i <nodes; ++i)
    {
      ll m;
      cin>>m;
      while(m--)
      {
        cin>>x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
        
      }
    }

    first_encounter.resize(nodes);
    dfs_euler_tour(0, -1);
    RMQ rmq(euler_tour);
ll q;
cin>>q;
cout<<"Case "<<test<<":\n";
while(q--)
{
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    ll fe1 = first_encounter[u];
    ll fe2 = first_encounter[v];
    if (fe1 > fe2)
        swap(fe1, fe2);
    ll LCA_new_index = rmq.minimum(fe1, fe2+1);
    ll LCA_old_index = new_to_old[LCA_new_index] + 1;
    c(LCA_old_index);
   // cout << "LCA_old_index: " << LCA_old_index << endl;
}}
}
signed main(){

        ios_base::sync_with_stdio(false);   
        cin.tie(NULL);
       solve();
    return 0;
    }
