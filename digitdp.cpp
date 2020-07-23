
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define eb          emplace_back
#define c(P)        cout<<P<<"\n"
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mp(x,y)     make_pair(x,y) 
#define exit(x)     cout<<x<<"\n",return
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,a,n)   for(ll i=a;i<n;i++)
#define frr(i,a,n)  for(ll i=n-1;i>=a;i--)


const ll N   =  500005;
const ll mod = 1e9 + 7;
using namespace std;

string to_string1(ll num)
{
  if(num==0)
    return "0";
  string str;
  while(num)
  {
    str+=char(num%10+'0');
    num/=10;
  }
  reverse(str.begin(),str.end());
  return str;
}
ll dp[20][2][2][3][2][5][2][7][2][11][2];
// TO SEE STATES SEE SOLVE FUNC
string s;
ll solve(int pos,int mo2,bool div2,int mo3,bool div3,int mo5,bool div5,int mo7,bool div7,int prev,int tight)
{
    if(pos==s.size())
        {
          
          if((mo2>0 and div2==1) or (mo3>0 and div3==1) or (mo5>0 and div5==1) or (mo7>0 and div7==1))
          {
            return 0;
          }                         
          return 1;
        }
    if(dp[pos][mo2][div2][mo3][div3][mo5][div5][mo7][div7][prev][tight]!=-1)
    {
      return dp[pos][mo2][div2][mo3][div3][mo5][div5][mo7][div7][prev][tight];
    }
    int d = s[pos] - '0';
    ll sum=0;
    for (int i = 0; i < 10; ++i)
    {
      if(!tight and i>d) break;
          if(__gcd(prev,i)!=1)
          {
              
                 
                  sum += solve(pos + 1,(mo2*10 + i)%2,div2 | (i==2),(mo3*10 + i)%3,div3 | (i==3),(mo5*10 + i)%5,div5 | (i==5) ,(mo7*10 + i)%7,div7 | (i==7),i,tight | (i<d) );
          }
    }
       return dp[pos][mo2][div2][mo3][div3][mo5][div5][mo7][div7][prev][tight] = sum;

}


signed main(){
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif
      ios_base::sync_with_stdio(false);   
      cin.tie(NULL);
      int T=1;
      while(T--)
      {
      ll a,b;
      cin>>a>>b;
      if(a>b) swap(a,b);
      memset(dp,-1,sizeof(dp));
      s=to_string1(b);

      ll ans1=solve(0,0,0,0,0,0,0,0,0,0,0);
      if(a==1)  {
        cout<<ans1-1<<"\n";
      return 0;
    }
      memset(dp,-1,sizeof(dp));
      s=to_string1(a-1);
      ll ans2=solve(0,0,0,0,0,0,0,0,0,0,0);
      cout<<ans1 - ans2<<endl;
      }
      return 0;
    }
