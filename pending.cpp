
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
bool vis[N];
ll dp[20][9][9][1][512][2];
int m,gmsk;

// TO SEE STATES SEE SOLVE FUNC
string s;
std::vector<ll> v,v1;
ll solve(int pos,int prev,int length,bool flag,int mask,int tight)
{
    if(length>=2*m)
        return 0;
    if(pos==s.size())
    { ll p =mask&gmsk;
            for(auto i : v)
              cout<<i;
            cout<<" ";
            for(auto i : v1)
              cout<<i;

            c("");
          if((mask&gmsk)==gmsk)return 1;
          return 0;
    }

    if(dp[pos][prev][length][flag][mask][tight]!=-1)
    {
      return dp[pos][prev][length][flag][mask][tight];
    }

    int d = s[pos] - '0';
    ll sum=0;
    v.clear();
    v1.clear();
    for (int i = 1; i < 10; ++i)
    {
      if(!tight and i>d) break;

          if(vis[i]==1 and flag==0)
          {  
           if(i>prev and length<=m){
                v.pb(i);
                      sum += solve(pos + 1,i,length+1,0,mask | (1LL << (i-1)),tight | (i<d));
                     }        else if(i<prev and length<2*m){
                            v.pb(i);
                             sum +=solve(pos + 1,i,length+1,0,mask | (1LL << (i-1)),tight | (i<d));
                  }
          }
          if(vis[i]==1  and (flag==1 or (flag==0 and length==0)))
          {    
            if(i<prev and length<=m)
            { v1.pb(i);
           sum += solve(pos + 1,i,length+1,1,mask | (1LL << (i-1)),tight | (i<d));
         }
           else if(i>prev and length<2*m)
           { v1.pb(i);
           sum += solve(pos + 1,i,length+1,1,mask | (1LL << (i-1)),tight | (i<d));
            }
          //cout<<sum;

          }


    }
       return dp[pos][prev][length][flag][mask][tight] = sum;

}

signed main(){
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif
      ios_base::sync_with_stdio(false);   
      cin.tie(NULL);
      int T=1;
      cin>>T;
      while(T--)
      {
      ll a,b,n,x;
      cin>>n;
      gmsk=0;
      for (int i = 0; i < n; ++i)
      { cin>>x;
       gmsk|=(1LL<<(x-1));
        vis[x] = 1;
       // cout<<x<<" ";
      }
       // c(gmsk);
      cin>>m>>a>>b;
      if(a>b) swap(a,b);
      memset(dp,-1,sizeof(dp));
      s=to_string1(b);
      ll ans1=solve(0,0,0,0,0,0);
      //c(ans1);
      memset(dp,-1,sizeof(dp));
      s=to_string1(a-1);
      ll ans2=solve(0,0,0,0,0,0);
      cout<<ans1 - ans2<<endl;
      c("");
      }
      return 0;
    }
