//Given a tree T of N nodes, where each node i has Ci coins attached with it. You have to choose
 // a subset of nodes such that no two adjacent nodes(i.e.
 // nodes connected directly by an edge) are chosen and sum of coins attached with nodes in chosen subset is maximum. 
//1} using twp dps
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
#define frr(i,a,n)  for(ll i=n-1;i>=a;i--)
const ll N=500005;
const ll mod = 1e9 + 7;

using namespace std;
//adjacency list
//adj[i] contains all neighbors of i
vector<int> adj[N];

//functions as defined above
int dp1[N],dp2[N],C[N];

//pV is parent of node V
void dfs(int V, int pV){

    //for storing sums of dp1 and max(dp1, dp2) for all children of V
    int sum1=0, sum2=0;

    //traverse over all children
    for(auto v: adj[V]){
    if(v == pV) continue;
    dfs(v, V);
    sum1 += dp2[v];
    sum2 += max(dp1[v], dp2[v]);
    }

    dp1[V] = C[V] + sum1;
    dp2[V] = sum2;
}

int main(){

    int n,x,y;
    cin >> n;

   for (int i = 1; i <= n; ++i)
   {
    cin>>C[i];
   }
    for(int i=1; i<n; i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    }

    dfs(1, 0);
    int ans = max(dp1[1], dp2[1]);
    cout << ans << endl;
}


//2} Using only one dp

#include<bits/stdc++.h>
using namespace std;
vector<int> v[12345];
int dp[12345];
void dfs(int curr,int parent)
{
    for(auto child:v[curr]){
        if(child==parent) continue;
        dfs(child,curr);
    }
    int take = dp[curr];
    int not_take = 0;
    for(auto child:v[curr])
    {
        if(child==parent) continue;
        not_take+=dp[child];
    }
    dp[curr]=max(dp[curr],max(take,not_take));
}
int main()
{
    int nodes;
    cin>>nodes;
    for(int i=1;i<nodes;++i){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    // enter value of each node
    for(int i=1;i<=nodes;++i){
        cin>>dp[i];
    }
    dfs(1,-1);
    cout<<dp[1]<<endl;
    cout.flush();
    return 0;
}