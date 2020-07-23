
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
const ll N=500005;
const ll mod = 1e9 + 7;

using namespace std;


void solve()
{
  ll T=1;
  //cin>>T;
  while(T--)
  {
vector<ll> v = {5,2,4,7,6,3,1,2,5,2,4,7,6,3,1,2,5,2,4,7,6,3,1,2,5,2,4,7,6,3,1,2,5,2,4,7,6,3,1,2,5,2,4,7,6,3,1,2,5,2,4,7,6,3,1,2,5,2,4,7,6,3,1,2};

vector<ll>  log_table(v.size()+1,0);
 for (int i = 2; i < log_table.size(); ++i)
 {
   log_table[i] = log_table[i/2] + 1;
 }  
 std::vector<vector<ll>> sparse_table(log_table.back()+1,std::vector<ll>(v.size()));
 sparse_table[0] = v;
for(int row=1;row<sparse_table.size();row++)
{
  for(int i=0;i + (1<<row) <=v.size();i++)
  {
    sparse_table[row][i] = min(sparse_table[row-1][i],sparse_table[row-1][i+(1<<(row-1))]);
  }
 }
 ll c=0;
 c(log_table[33]);
 while(c--)
 {
  ll l,r;
  cin>>l>>r;
  ll lg = log_table[r-l];

  ll minimun = min(sparse_table[lg][l],sparse_table[lg][r - (1<<lg)]);
  c(minimun);
 }
}

}

signed main(){
     
        ios_base::sync_with_stdio(false);   
        cin.tie(NULL);
       solve();
    return 0;
    }
