
#include<bits/stdc++.h>
#define ll          int
#define pb          push_back
#define eb          emplace_back
#define c(P)        cout<<P<<"\n"
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mp(x,y)     make_pair(x,y) 
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,a,n)   for(ll i=a;i<n;i++)
#define frr(i,a,n)  for(ll i=n-1;i>=a;i--)
const ll N   =  50015;
const ll mod = 1e9 + 7;

using namespace std;
struct node{
ll prefixsum,suffixsum,segsum,maxsum;
};
node tree[4*N];

void build(ll a[],ll low,ll high,ll index)
{
  if(low==high)
  {
    tree[index].segsum =tree[index].maxsum = tree[index].prefixsum=tree[index].suffixsum = a[low];
    return;
  }
  ll mid = (low + high)/2;
  build(a,low,mid,2*index);
  build(a,mid+1,high,2*index+1);
  //sums
  tree[index].segsum       = tree[2*index].segsum + tree[2*index+1].segsum; 
  tree[index].prefixsum = max(tree[2*index].prefixsum,tree[2*index].segsum+ tree[2*index+1].prefixsum);
  tree[index].suffixsum = max(tree[2*index+1].suffixsum,tree[2*index+1].segsum+ tree[2*index].suffixsum);
  tree[index].maxsum    = max({tree[index].prefixsum,tree[index].suffixsum,tree[2*index].maxsum,tree[2*index+1].maxsum,tree[2*index].suffixsum+tree[2*index+1].prefixsum});
}

node query(ll a[],ll index,ll low,ll high,ll l,ll r)
{
  node result;
  result.prefixsum = result.suffixsum = result.segsum = result.maxsum = INT_MIN;
  if(r<low or high<l)
  {
    return result;
  }
  if(l<=low and high<=r)
  {
    return tree[index];
  }
  ll mid  = (low + high)/2;
  if(l>mid)
  {
    return query(a,2*index + 1,mid +1,high,l,r);
  }

  if (r <= mid) 
    return query(a, 2 * index, low, mid, l, r); 
  
   node left  = query(a, 2 * index, low, mid, l, r); 
   node right = query(a, 2 * index + 1,mid + 1, high, l, r); 
  
    // finding the maximum and returning it 
   result.segsum       = left.segsum + right.segsum; 
   result.prefixsum    = max(left.prefixsum,left.segsum+ right.prefixsum);
   result.suffixsum    = max(right.suffixsum,right.segsum+ left.suffixsum);
   result.maxsum       = max({result.prefixsum,result.suffixsum,left.maxsum,right.maxsum,left.suffixsum+right.prefixsum});

                      
    return result; 
}
void update(ll a[],ll index,ll low,ll high,ll idx,ll value)
{
  if(low == high)
  {
    tree[index].segsum =tree[index].maxsum = tree[index].prefixsum=tree[index].suffixsum = value;
    return;
  }
  ll mid = (low + high)/2;
  if(idx<=mid)
  {
    update(a,2*index,low,mid,idx,value);
  }
  else 
  {
    update(a,2*index+1,mid+1,high,idx,value);
  }
  //sums
  tree[index].segsum    = tree[2*index].segsum + tree[2*index+1].segsum; 
  tree[index].prefixsum = max(tree[2*index].prefixsum,tree[2*index].segsum+ tree[2*index+1].prefixsum);
  tree[index].suffixsum = max(tree[2*index+1].suffixsum,tree[2*index+1].segsum+ tree[2*index].suffixsum);
  tree[index].maxsum    = max({tree[index].prefixsum,tree[index].suffixsum,tree[2*index].maxsum,tree[2*index+1].maxsum,tree[2*index].suffixsum+tree[2*index+1].prefixsum});
}




void solve()
{
// string s;
  ll n,m,k,x=0,y=0,c=0,q,ans=0;
  cin>>n;
  ll a[n+1];
  for (ll i = 1; i <= n; ++i)
  {
  cin>>a[i];
  }
  build(a, 1, n, 1);
  cin>>k;
  while(k--)
  {
    cin>>q>>x>>y;
    if(q==1)
    cout<<query(a,1,1,n,x,y).maxsum<<'\n';
    else update(a,1,1,n,x,y);

  }

}

signed main(){
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif
      ios_base::sync_with_stdio(false);   
      cin.tie(NULL);
      ll T=1;
      //cin>>T;
      while(T--)
      {
      solve();
      }
      return 0;
    }
