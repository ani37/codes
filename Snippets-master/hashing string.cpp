
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"
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
    ll power(ll a, ll b,ll m)    //a is base, b is exponent
    {
        if(b==0)
            return 1;
        if(b==1)
            return a%m;
        if(b%2 == 1)
            return (paower(a,b-1,m)*a)%m;
        ll q = power(a,b/2,m);
        return (q*q)%m;
    }
ll hsh(string s,ll p ,ll m)
{
    ll res=0,np=1;
 for (int i = 0; i < s.size(); ++i)
 {
     res=(res+(s[i]-'a'+1)*np)%m;
     np=np*p%m;
 }
 return res;
}
void solve(){

  ll x=0,y=0,c=0,p1=31,p2=29,q,t;
  ll n,m,k;
  cin>>n>>q;
  string st;
  std::set<pii> s;
  for (ll i = 0; i < n; ++i)
  {
  cin>>x>>st;
  x = hsh(st,31,mod);
  y = hsh(st,29,mod);
  s.insert({x,y});
  }
  cin>>x>>st;
  pii ans = {hsh(st,31,mod),hsh(st,29,mod)}; 
        char ch;
        deque<char>dq;
    for(char cd: st)
        dq.pb(cd);
  while(q--)
  {
    cin>>t;
    if(t==1)
    {
        cin>>ch;
        dq.push_front(ch);
       ans.F = (ans.F*p1 + ch -'a'+1)%mod;
       ans.S = (ans.S*p2 + ch -'a'+1)%mod;
    }
    else if(t==2)
    {
         cin>>ch;
         x = dq.size();
         dq.pb(ch);
      ans.F = (ans.F + (ch -'a'+1)*power(p1,x,mod)%mod)%mod;
      ans.S = (ans.S + (ch -'a'+1)*power(p2,x,mod)%mod)%mod;   
    }
    else if(t==3)
    {
        ch = dq.front();
        dq.pop_front();
       ans.F = (ans.F - (ch -'a'+1)+ mod)%mod;
       ans.F = ans.F*power(p1,mod-2,mod)%mod;
       ans.S = (ans.S - (ch -'a'+1) + mod)%mod;
       ans.S = ans.S*power(p2,mod-2,mod)%mod;
    }
    else if(t==4)
    {
        ch = dq.back();
        dq.pop_back();
        x = dq.size();
      ans.F = (ans.F - (ch -'a'+1)*power(p1,x,mod)%mod+mod)%mod;
      ans.S = (ans.S - (ch -'a'+1)*power(p2,x,mod)%mod+mod)%mod; 
    }
    else
    {
      //  cout<<ans.F<<" "<<ans.S<<'\n';
        
        if(s.find(ans)!=s.end())
        {
            c("yes");
        }
        else c("no");
    }
  }

}

signed main(){
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  ll T=1;
  //cin>>T;
  while(T--){
  solve();
  }
  return 0;
}
