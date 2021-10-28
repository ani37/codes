
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

  ll n,m,k,x=0,y=0,c=1,q,ans=0;
  cin>>n;
  string s[2];
  cin>>s[0]>>s[1];
  for (ll i = n-1; i >0; --i)
  { 
       
      if(s[c][i]=='1' or s[c][i]=='2')
        continue;
      if(s[c^1][i]!='1' and s[c^1][i]!='2')
      {
        c^=1;
      }
      else
      {
        c("NO");
        return;
      }
  }
  if(c==0)
  {
    if(s[c][0]=='1' or s[c][0]=='2')
    {
      c("YES");
      return;
    }
  }
  else
  {
   if(s[1][0]!='1' and s[1][0]!='2' and s[0][0]!='1' and s[0][0]!='2' )
    {
      c("YES");
      return;
    } 
  }
  c("NO");
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
