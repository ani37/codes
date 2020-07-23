
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


const ll N   =  200005;
const ll mod = 1e9 + 7;


vector<ll> adj[N];

vector<ll> time_in(N), time_out(N),br(N),h(N),vis(N);

ll dp[N][20];
ll dfs_timer = 0;
ll n;
std::map<pii , ll> mp;

void dfs(ll v,ll p) {
	
	 
		h[v] = 1;

		ll cnt = 0,cnt2 = 0;
		
		for (ll u : adj[v]){

				 if(u==p) continue;

					if (h[u] == 0){	
						dfs(u,v);
						br[v]+=br[u];
				}
				else {

					if(h[u]==1){
						cnt++; // edges going up
					}

					else cnt2++; // edges going down
				}
		}

		br[v] +=cnt - cnt2;

		if(br[v]==0){   // bridge edges
		//	c((mp[{v,p}]));
		 vis[mp[{v,p}]] =1;
		}
		h[v] = 2;
}

void solve(){

	ll m,k,x=0,y=0,q,ans=0;

	cin>>n >> m;
	for (int i = 1; i <= m; ++i)
	{
	 cin>>x>>y;

	 adj[x].pb(y);
	 adj[y].pb(x);
	 mp[{x,y}] = i;
	 mp[{y,x}] = i;
	}
	fr(i,1,n+1){

    if(h[i]==0) dfs(i,-1);
  }

	cin>>q;

	while(q--){
		cin >> x;
		if(vis[x])ans++;
	}
	c(ans);
}

		int main(){

				ios_base::sync_with_stdio(false);   
				cin.tie(NULL);
			 solve();
		return 0;
		}
