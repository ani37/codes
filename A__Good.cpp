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
 
 
const ll N   =  500005;
const ll mod = 1e9 + 7;
 
 
 
void solve(){
 
  ll x=0, y=0, c = 0, ans = 0;
  ll n, m, k;
  
  cin >> n >> k;
  vector<ll> cnt(26);
  string s;
  cin >> s;
  for (ll i = 0; i < n; ++i){
    cnt[s[i]-'a']++;
  }
  ans = 1;
  for (ll i = 2; i <= n; ++i){
    if(k % i == 0){
      ans = i;
      continue; 
    }
    bool fl = 0;
 
 
    
    priority_queue <ll> pq;
 
    
    for (ll j = 0; j < 26; ++j){
      pq.push(cnt[j]);
      //c(cnt[j]);
    }
 
    vector<bool>vis(i+1,0);
   // cout <<i <<" ->";
    for (ll j = 0; j < i; j++){
           
        c = 0;
 
 
        if(!vis[j]){
          
         while(!vis[j]){
 
            c++;
            vis[j] = 1;
            j+=k;
            j %= i;
          //  c(j);
            
         }
         
         // c(pq.top());
         if(pq.size() and pq.top() >= c){
            x = pq.top();
            pq.pop();
          x-=c;
           pq.push(x);
         }
         else {
          fl = 1;
          break;
         }
        }
    }
    if(fl==1)continue;
    ans = i;
 
 
  }
    c(ans);
 
}
 
signed main(){
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  int T;cin >> T;while (T--)
  solve();
  return 0;
}