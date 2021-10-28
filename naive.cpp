
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"

using namespace std;
const ll mod = 1e9 + 7;

signed main(){
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);

  ll x=0,y=0,c=0,ans=0;
  ll n;
  cin>>n;
  string s[n];
  for (int i = 0; i < n; ++i)
  {
      cin>>s[i];
  }
  for (int i = 0; i < n; ++i)
  {
     for (int j = i+1; j <n; ++j)
     {
      c=0;
      x = min(s[i].size(),s[j].size());
       for (int k = 0; k < x; ++k)
       {
        if(s[i][k]==s[j][k])
          c++;
        else break;
       }
       ans+= c*c;
       ans%=mod;
     }
  }
  c(ans);
  return 0;
}
