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
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)
using namespace std;
 
 
const ll N   =  500005;
const ll mod = 1e9 + 7;
bool vis[N];
ll col[N], cnt[N], ans[N], depth[N],frequeries[N];
//freq stores frequency of the index, and cnt stores the frequencies that have passed that index
 ll t = 0,block =750,ans_mx;
//for queries
struct query {
    ll l, r, idx;
};

vector<query> queries(N);

bool com(query a,query b){
  if(a.l/block!=b.l/block)
    return a.l<b.l;
  return a.r<b.r;
}
//These functions are used in Mo's Algorithm
void add(ll val) {

    ans_mx += (2*(frequeries[val])+ 1) * val;
    frequeries[val]++;
}
 
void rem(ll val) {

    frequeries[val]--;
    ans_mx -= (2*(frequeries[val])+ 1) * val;
} 
 
 
 
void solve(){
 
  ll n,m,k,x,y;
  cin>>n >> m;
 
 //block = sqrt(n);
 for(ll i=0;i<n;i++)
        cin >>col[i];
 

  for(ll i=1;i<=m;i++){
    
    queries[i].idx = i;
    cin >> queries[i].l;
    queries[i].l--;
    cin >> queries[i].r;
    queries[i].r--;
  }
 
  sort(queries.begin()+1, queries.begin()+1+m,com);
 
  ll curl = queries[1].l,curr = queries[1].l-1;
 
    for(long long i = 1; i <= m; i++) {
       
        while(curl < queries[i].l) {
              
            rem(col[curl++]);
        }
        
        while(curl > queries[i].l) {
           // cout<<col[curl]<<" "<<curl<<"\n";
            add(col[--curl]);
        }
        
        while(curr < queries[i].r) {
          //cout<<col[curr]<<" "<<curr<<"\n";
            add(col[++curr]);
        }
        //c("");
        while(curr > queries[i].r) {
         // cout<<col[curr]<<" "<<curr<<"\n";
            rem(col[curr--]);
        }
    
        ans[queries[i].idx] = ans_mx;
    }
 
    //Outputting answer
    for(ll i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
    }
}
 
signed main(){  
      
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  //ll T;cin >> T;while (T--)
  solve();
  return 0;
}