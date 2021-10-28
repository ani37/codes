
//https://codeforces.com/contest/510/problem/B
// nice problem in grid to find cycle if same chars are found..
#include<bits/stdc++.h>
#define ll          int
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
ll n,m;
string board[51];
bool vis[51][51];
bool findcycle = false;
ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};
void dfs(ll x,ll y,ll fromX,ll fromY,char needColor)
{
   //see initial conditions properly
    if(x<0 or y<0 or x>=n or y>=m) return; //base case
    if(board[x][y] != needColor) return;
    //other condition
    if(vis[x][y])
    {
        findcycle = true;
        return;
    }
    vis[x][y] = true;
    // same for most ie traversal
    for (int f = 0; f < 4; ++f)
    {
        ll nextX = x + dx[f];
        ll nextY = y + dy[f];
        if(nextX==fromX and nextY==fromY) // check for vis node
                continue;
        dfs(nextX,nextY,x,y,needColor);

    }
}
void solve()
{
  ll T=1;
  //cin>>T;
  while(T--)
  {

  cin>>n>>m;
  mem(vis,false);

  for (ll i = 0; i < n; ++i)
  {
     cin>>board[i];
  }
  for (ll i = 0; i < n; ++i)
  {
      for(ll j=0;j<m;j++)
      {
        if(!vis[i][j])
            dfs(i,j,-1,-1,board[i][j]);
      }
  }
 cout << (findcycle ? "Yes" : "No") << "\n";
 }
}
signed main(){
      #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
      #endif
        ios_base::sync_with_stdio(false);   
        cin.tie(NULL);
       solve();
    return 0;
    }
