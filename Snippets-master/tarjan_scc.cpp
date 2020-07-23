int counter=0;
void cycle(int i, auto& disc, auto& low, auto& adj, auto& path, auto& vis)
{
	disc[i]=low[i]=++counter;
	path.push(i);
	vis[i]=true;

	for(auto x:adj[i])
	{
		if(disc[x]==-1)
		{
			cycle(x,disc,low,adj,path,vis);
			low[i]=min(low[i],low[x]);
		}
		else if(vis[x])
		{
			low[i]=min(low[i],disc[x]);
		}
	}

	if(low[i]==disc[i])
	{
		while(path.top()!=i)
		{
			cout<<path.top()<<" ";
			vis[path.top()]=false;
			path.pop();
		}
		cout<<i<<"\n";
		vis[i]=false;
		path.pop();
	}
}
void tarjan_scc(vector< list<int> >& adj)
{
	int n=adj.size();

	vector<int>low(n,-1);
	vector<int>disc(n,-1);
	stack<int>path;
	vector<bool>vis(n,0);

	for(int i=1;i<n;i++)
	{
		if(disc[i]==-1)
		{
			cycle(i,disc,low,adj,path,vis);
		}
	}
}
// maxtax scc
#include <bits/stdc++.h>

using namespace std;

const int MX = 100000, md = 1000000021;

vector<int> G[MX], G_out[MX], G_in[MX], current, B[MX];
int b[MX], vis[MX], comp[MX];

void dfs(vector<int> G[MX], int v, int f) {
  if (vis[v] != f) return;
  vis[v] ^= 1;
  for (int u : G[v]) dfs(G, u, f);
  current.push_back(v);
}

int main() {
  int T;
  ignore = scanf("%d", &T);
  while (T--) {
    int n, m, k;
    ignore = scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
      ignore = scanf("%d", b + i);
      G[i].clear();
      G_out[i].clear();
      G_in[i].clear();
      B[i].clear();
      comp[i] = -1;
    }
    for (int i = 0, u, v; i < m; i++) {
      ignore = scanf("%d %d", &u, &v);
      u--; v--;
      G_out[u].emplace_back(v);
      G_in[v].emplace_back(u);
    }
    
    for (int i = 0; i < n; i++) dfs(G_out, i, 0);
    
    int cnt = 0;
    vector<int> order = current;
    reverse(order.begin(), order.end());
    for (int v : order) {
      if (vis[v] == 0) continue;
      current.clear();
      dfs(G_in, v, 1);
      for (int u : current) {
        comp[u] = cnt;
        B[cnt].push_back(b[u]);
        for (int p : G_in[u]) {
          if (comp[p] != cnt && comp[p] != -1) {
            G[comp[p]].push_back(cnt);
          }
        }
      }
      sort(B[cnt].begin(), B[cnt].end());
      cnt++;
    }
    // B stores the SCC part
    
    int64_t ans = 0;
    vector<vector<int64_t>> dp(cnt, vector<int64_t>(k + 1, 0));
    for (int v = 0; v < cnt; v++) {
      int64_t size = B[v].size();
      for (int f = k; f >= 0; f--) {
        for (int c = 0; c <= f && c <= size; c++)
          dp[v][f] = max(dp[v][f], dp[v][f - c] + B[v][c] * (size - c));
        
        ans = max(dp[v][f], ans);
        
        for (int u : G[v]) dp[u][f] = max(dp[u][f], dp[v][f]);
      }
    }
    
    printf("%d\n", (int)(ans % md));
  }
  
  return 0;
}


