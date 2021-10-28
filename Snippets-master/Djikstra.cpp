std::vector<pii> adj[N];
std::vector<bool> vis(N);
std::vector<ll> dis(N);
  ll n;
void dijkstra(ll x)
{
for (int i = 0; i <=n ; ++i)
  {
    dis[i] =1e18;
    vis[i] = 0;
  }
  dis[x] = 0;
  priority_queue<pii,std::vector<pii> ,greater<pii> >pq;
  pq.push({0,x});
  while(!pq.empty())
  {
    ll top = pq.top().S;
    pq.pop();
    if(vis[top])continue;
    vis[top] = 1;
    for (auto i : adj[top])
    {
      if(vis[i.F])continue;
      if(dis[i.F]>dis[top] + i.S)
      {
        dis[i.F] = dis[top] + i.S;
        pq.push({dis[i.F],i.F});
      }
    }
  }
}
