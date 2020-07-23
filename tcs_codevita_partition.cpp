#include<bits/stdc++.h>
#define ll          long long
using namespace std;

const ll mod = 1e9 + 7;


void solve()
{
    string s;
    ll k,m,n,x=0,y=0,c=0,q,ans=0;
    cin>>n>>m;
    ll possible[n+5][n+5];
    ll sufsum[n+5][n+5];

    memset(possible,0LL,sizeof(possible));
    memset(sufsum,0LL,sizeof(sufsum));
    possible[n][0] =1;

    for(ll i= n-1;i>=0;i--){
      for (ll part = 0; part<=n ; ++part){
         
            sufsum[i][part] = (sufsum[i+1][part] + possible[i+1][part])%mod;
      }
        for (ll part = 1; part<=n ; ++part){
          if(i+m-1<n){
            possible[i][part] = sufsum[i+m-1][part-1];
          }
      } 
    } 
  for (int i = 0; i <= n; ++i)
  c+=possible[0][i];
c%=mod;
cout<<c<<'\n';
}
signed main(){
      ios_base::sync_with_stdio(false);   
      cin.tie(NULL);
      ll T=1;
      cin>>T;
      while(T--)
      {
      solve();
      }
      return 0;
    }