//https://www.codechef.com/BION2019/problems/SPAR3
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int MOD = 1e9 + 7 ;

int32_t main(){
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
      #endif
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      
      int t;
      cin>>t;
      while(t--)
      {
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
        int dp[n][m];        
        for(int i=0;i<n;i++)
        {
          dp[i][0]=a[i][0]+(i-1>=0?dp[i-1][0]:0);
        }

        for(int j=1;j<m;j++)
        {
          int dp1[n];
          int dp2[n];
          for(int i=0;i<n;i++)
          {
            dp2[i]=dp1[i]=dp[i][j-1]+a[i][j];
           // cout<<dp1[i]<<" ";
          }
          //cout<<"\n";
          for(int i=1;i<n;i++)
          {
            dp1[i]=max(dp1[i],dp1[i-1]+a[i][j]);
           // cout<<dp1[i]<<" ";
          }
          // cout<<"\n";
          for(int i=n-2;i>=0;i--){
            dp2[i]=max(dp2[i],dp2[i+1]+a[i][j]);
          }
          for(int i=0;i<n;i++) dp[i][j]=max(dp1[i],dp2[i]);
        }
        cout<<dp[n-1][m-1]<<"\n";
      }
}  