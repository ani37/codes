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
 
ll a[] ={1,2,5,10,20,50,100};
ll b[] = {5,10,20,50,100,200};
void solve()
{
// string s;
  ll n,m,k,x=0,y=0,c=0,q,ans=0,e,d;
  cin>>n>>d>>e;
  x = n;
  x%=d;
  x%=(5*e);
  ans = x;
  x = n;
  x%=(5*e);
  x%=d;
  ans = min(x,ans);
  x = n;
  x%=(5*e);
  while(n>5*e)
  {
    n -= 5*e;
    x  =n;
    x%=d; 
  ans = min(x,ans);
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
      //cin>>T;
      while(T--)
      {
      solve();
      }
      return 0;
    }
