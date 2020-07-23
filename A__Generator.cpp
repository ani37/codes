
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
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)
#define randint(x,y) uniform_int_distribution<int>(x, y)(rng)

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve(){

  ll x=0,y=0,c=0,ans=0;
  ll n,m,k,q;
  m =10;
  n = randint(1, 2000);
 //cout << n <<" " << randint(1, 2000) <<'\n';
  for (ll A = 1; A <=20; ++A){
    
  cout << A <<"\n";
   for (ll i = 0; i < A; ++i){
    for (ll j = 0; j < A; ++j){
     cout <<  randint(0, 2000) <<" ";
    }
     cout << '\n';
   }
  }
  // for (ll i = 0; i < n; ++i){
  //    cout << (char)(randint(0, 1)+'a');
  //   //   cout << randint(-10, 10)<<" "<< randint(-10, 10)<<" "<< randint(-10, 10)<<'\n';
  //   // //   int y = randint(x+1,m);
  // }
  // c("");
    
  // n = 1e6;
  // //  }
  //    cout << n << " " << 2 << '\n';
  //     cout << "ccgggg";
  //     for (ll j = 0;j < n-8; ++j){
  //       cout << (char)(randint(0,25) + 'a') ;
  //     }
  //     c("ccgg");
    // while(q--){
    //   int x = randint(1, m - 1);
    //   int y = randint(x+1,m);
    //   cout << x <<" " << y << '\n';
    // }
  // c("");
  // cout << 100000 <<"\n";
  // for (ll i = 0; i < 100000; ++i){
  //   x = randint(1,70000);
  // cout <<x <<" "<< randint(x,100000)<<"\n";
  // }
}

signed main(){
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  cout << 20 <<"\n";
  int T = 20;//cin >> T;
  while (T--)
  solve();
  return 0;
}
