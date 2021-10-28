#include<bits/stdc++.h>
    #define ll          long long
    #define pb          push_back
    #define c(P)        cout<<P<<"\n"
    #define pii         pair<ll,ll>
    #define mi          map<ll,ll>
    #define mii         map<pii,ll>
    #define F           first
    #define S           second
    #define sz(a)       (ll)(a.size())
    #define cr(P)       cout<<P<<"\n";return;
    #define mem(a,val)  memset(a, val, sizeof(a))
    #define fr(i,x,n)   for(ll i=x; i<n; i++)
    #define frr(i,x,n)  for(ll i=n-1; i>=x; i--)
    using namespace std;


    const ll N   =  195;
    const ll mod = 1e9 + 7;
    ll n, m, k;
    mii mp;
  //  ll dp[N][3][5][5][5][5][5][5];
    std::map<pair<vector<ll>, vector<ll> >, bool> mp;
    vector<vector<ll>> ans;
    
    void f(vector<ll> a, vector<ll> b){

            
        ll &ans = dp[idx][col][a1][a2][a3][a4][a5][a6];
        if(ans!=-1)
            return ans;
        ans = 0;
        ans= (ans + f(idx+1,col,a1,a2,a3,a4,a5,a6))%mod;

        if(col==0){
            if(a1>0){
                ans= (ans + f(idx+1, 1,a1-1,a2,a3,a4,a5,a6))%mod;
            }
            if(a2>0){
                ans= (ans + f(idx+1, 2,a1,a2-1,a3,a4,a5,a6))%mod;
            }
        }

        if(col==1){
            if(a3>0){
                ans= (ans + f(idx+1, 0,a1,a2,a3-1,a4,a5,a6))%mod;
            }
            if(a4>0){
                ans= (ans + f(idx+1, 2,a1,a2,a3,a4-1,a5,a6))%mod;
            }
        }
        if(col==2){
            if(a5>0){
                ans= (ans + f(idx+1, 0,a1,a2,a3,a4,a5-1,a6))%mod;
            }
            if(a6>5){
                ans= (ans + f(idx+1, 1,a1,a2,a3,a4,a5,a6-1))%mod;
            }
        }
       
        ans %= mod;
        return ans;
    }



    void solve(){

     ll x=0, y=0, c = 0;
     cin >> n;
     mem(dp,-1);
     vector<ll>v;
     mp[{0,1}]= 0; // RO
     mp[{0,2}]= 1; // RG
     mp[{1,0}]= 2; // OR
     mp[{1,2}]= 3; // OG
     mp[{2,0}]= 4; // GR
     mp[{2,1}]= 5; // GO

     for (ll i = 0; i <= 5; ++i){
        cin >> x;
        v.pb(x);
     }
     vector<ll> a;
     
     ans.pb({1});
     ans.pb({2});
     ans.pb({3});
     ans = f({2},v) + 
           f({1},v) + 
           f({0},v); 
     ans%=mod;
     c(ans);    
    }

    signed main(){
         
     ios_base::sync_with_stdio(false);   
     cin.tie(NULL);
     //int T;cin >> T;while (T--)
     solve();
     return 0;
    }

//     190
// 3
// 4
// 3 
// 2
// 3
// 3
// 792673831
// 20 
// 10
// 10
// 10
// 1
// 486784380

// 20

// 23456
// 429117207
// 20 123321
// 19926747

//415185618