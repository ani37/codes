
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"
#define dbg(P)      cout<<P<<" "
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)


const ll N   =  500005;
const ll mod = 1e9 + 7;

using namespace std;


void solve()
{
  string s;
  ll n,m,k,x=0,y=0,c=0,q,ans=0;
  cin>>s;
  n =s.size();
  std::vector<ll> dp(n);

  for (ll i = 0; i < n; ++i)
  {
    dp[i] = s[i] == '0' ? 1 : 0; 
    if(i>0)
    dp[i]+=dp[i-1];
  }
  for (int i = 0; i < n; ++i)
  {
     if(s[i]=='1')
      c++;
    if(c==0)
      continue;
    x = lower_bound(dp.begin(), dp.end(),c*c) - dp.begin();
    if(dp[x]!=c*c)
      x++;
    dbg(x);
    c(dp[i]);
    if(x<i)
    ans+= (i-x);

  }
  
  cout<<ans<<"\n";
}

signed main(){
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif
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
