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
  stack<char>st;
  ll n,m,k,c=0,q,ans=0;
  cin>>n>>s;
char x,y;
  for (ll i = 0; i < n; ++i)
  {
   if(st.empty())
    st.push(s[i]);
    else if(s[i]==')' and st.top()=='(')
        st.pop();
    else st.push(s[i]);
  }
  if(st.size()==0)
  {
    c("Yes");
    return;
  }
  if(st.size()%2==1 or st.size()>2)
  {
    c("No");
    return;
  }
  
    x = st.top();
    st.pop();
    y = st.top();
    if(x=='(' and y ==')')
      {
        c("Yes");
         return; 
      }
  c("No");
  
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
