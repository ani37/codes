
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
using namespace std;


const ll N   =  500005;
const ll mod = 1e9 + 7;



vector<ll> A(N), tree(N << 2),lazy(N<<2);
 
void build(ll node, ll start, ll end) {
    if (start == end) {
        tree[node] = A[start];
    }
    else {
        ll mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}
 
void update(ll node, ll start, ll end, ll left,ll right,ll val) {

  if(lazy[node]!=0){
      tree[node] +=(end-start+1)*lazy[node];
      if(start!=end){
         lazy[2*node] +=lazy[node];
         lazy[2*node+1] +=lazy[node];
      }
      lazy[node]=0;
  }
  if (start>=left and right>=end) {

      tree[node] +=(end-start+1)*val;
      if(start!=end)
      {
         lazy[2*node]   +=val;
         lazy[2*node+1] +=val;
      }
      return;
  }
  if (end < left || start > right || end<start)  
        return;

    ll mid = (start + end) / 2;
      update(2*node, start, mid, left,right, val);
      update(2*node+1, mid+1, end, left,right, val);
    tree[node] = tree[2*node] + tree[2*node+1];
    
}
 
ll query(ll node, ll start, ll end,ll left,ll right) {
    if (end < left || start > right || end<start)  
        return 0;  
    if(lazy[node]!=0){
      tree[node] +=(end-start+1)*lazy[node];
      if(start!=end)
      {
         lazy[2*node] +=lazy[node];
         lazy[2*node+1] +=lazy[node];
      }
      lazy[node]=0;
    }
   if (left <= start and right>=end) {
    return tree[node];
    }
   ll mid = (start + end) / 2;
   ll p1 = 0, p2 = 0;
   p2 = query(2*node+1, mid+1, end,left,right);
   p1 = query(2*node, start, mid,left,right);
   return (p1 + p2);
}
void solve()
{
  ll n,m,k,x=0,y=0,c=0,q,ans=0;
  cin>>n;

  for (ll i = 1; i <= n; ++i)
  {
  cin>>A[i];
  }
  build(1,1,n);
  update(1,1,n,1,4,1);
  c(query(1,1,n,1,5));
}

signed main(){
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  //int T;cin >> T;while (T--)
  solve();
  return 0;
}