// you are given two tpyes of queries 
// 1.  given four integers a,b,c,d where(a<=b<c<=d) reverse(a,b) and reverse(c,d) and exchange the elements in these position.
// 2. find the sum from l to r.

#include<bits/stdc++.h>
#define ll          int
#define pb          push_back
#define c(P)        cout<<P<<"\n"
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)
#define randint(x,y) uniform_int_distribution<int>(x, y)(rng)

const ll N   =  500005;
const ll mod = 1e9 + 7;

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef struct node{
    int prior,size,val,sum,lazy,rev;
    struct node *l,*r;
}node;typedef node* pnode;
int sz(pnode t){
    return t?t->size:0;
}

void upd_sz(pnode t)
{
    if(t)t->size=sz(t->l)+1+sz(t->r);
}
void push (pnode t)
 {
    if (t && t->rev)
     {
        t->rev = 0;
        swap (t->l, t->r);
        if (t->l)  t->l->rev ^= 1;
        if (t->r)  t->r->rev ^= 1;
    }
}

void lazy(pnode t)
{
    push(t);
    if(!t || !t->lazy)return;
    t->val+=t->lazy;//operation of lazy
    t->sum+=t->lazy*sz(t);
    if(t->l)t->l->lazy+=t->lazy;//propagate lazy
    if(t->r)t->r->lazy+=t->lazy;
    t->lazy=0;
}
void reset(pnode t)
{
    if(t)t->sum = t->val;//lazy already propagated
}
void combine(pnode& t,pnode l,pnode r)
{//combine segtree ranges
    if(!l || !r)return void(t = l?l:r);
    t->sum = l->sum + r->sum;
}
void operation(pnode t)
{//operation of segtree
    if(!t)return;
    reset(t);//node represents single element of array
    lazy(t->l);lazy(t->r);//imp:propagate lazy before combining l,r
    combine(t,t->l,t);combine(t,t,t->r);
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
    if(!t)return void(l=r=NULL);
    lazy(t); 
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)//element at pos goes to "l"
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else    split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);operation(t);
}
void merge(pnode &t,pnode l,pnode r){//result/left/right array
 
    lazy(l);lazy(r);
   
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else    merge(r->l,l,r->l),t=r;
    upd_sz(t);operation(t);
}
pnode init(int val){
    pnode ret = (pnode)malloc(sizeof(node));
    ret->prior= randint(1,INT_MAX);ret->size=1;
    ret->l = NULL;
    ret->r =NULL;
    ret->val=val;ret->sum=val;ret->lazy=0;ret->rev=0;
    return ret;
}
void reverse(pnode t,int l,int r)
{
    pnode L,mid,R;
    split(t,L,mid,l-1);split(mid,t,R,r-l);//note: r-l!!
    t->rev ^=1;
    merge(mid,L,t);merge(t,mid,R);
}
int range_query(pnode t,int l,int r){//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);split(mid,t,R,r-l);//note: r-l!!
    int ans = t->sum;
    merge(mid,L,t);merge(t,mid,R);
    return ans;
}
void range_update(pnode t,int a,int b,int c,int d){//[l,r]
    pnode L1,mid,R,L2,R2,ans1,ans2;
    split(t,L1,mid,a-1);split(mid,ans1,t,b-a);//note: b-a!!
    split(t,L2,mid,c-2-b);split(mid,ans2,R,d-c);//note: d-c!!
    ans1->rev^=1;
    ans2->rev^=1; 
    merge(mid,ans1,R);merge(t,L2,mid);
    merge(mid,ans2,t);merge(t,L1,mid);
}
void output (pnode t) {
    if (!t)  return;
    push (t);
    output (t->l);
    printf ("%d ", t->val);
    output (t->r);
}
signed main()
{
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
   ll n;
   cin>>n;
   ll a[n];
   for (int i = 0; i < n; ++i)
   {
    cin>>a[i];
   }
pnode Treap;
    for(int i=0;i<n;i++)
    {
        pnode it = init(a[i]);
        if(i == 0)
            Treap = it;
        else
            merge(Treap,Treap,it);
    }
    int q;
   cin>>q;
    while(q--)
    {
        int t,a,b,c,d;
        cin>>t;
        if(t==1)
        {
        cin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        range_update(Treap,a,b,c,d);
        }
        else
        {
          cin>>a>>b;
          a--;
          b--;
       ll x= range_query(Treap,a,b);
        c(x);
        }
    }
    return 0;
}
//Generator


// void solve()
// {
// // string s;
//   ll n,m,k,x=0,y=0,c=0,q,ans=0;
//   c(N);
//   srand(time(0)); 
//   for (ll i = 0; i < N; ++i)
//   {
//     cout<<rand()%mod<<" ";
//   }
//   c("");
//   c(N-5);
//   c = N-5;
//   k = N-10;
//   while(c--)
//   {
//    ll a[4];
//    a[0] = rand()%k+1;
//    a[1] = rand()%k+1;
//    a[2] = rand()%k+1;
//    a[3] = rand()%k+1;
//    sort(a,a+4);
//    if(a[0]==a[1])
//     a[1]+=1,a[2]+=1,a[3]+=1;
//    if(a[1]==a[2])
//     a[2]+=1,a[3]+=1;
//    if(a[2]==a[3])
//     a[3]+=1;
//   if(c%2==1)
//   {
//     cout<<1<<" "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<'\n';
//   }
//   else cout<<2<<" "<<a[0]<<" "<<a[2]<<"\n";
//   }

// }



2. You are given a string and in each second the string shifts by k(1<=k<=n) 
chars to the left and you have to fill k chars each time. You have
 find the minimum time such that the string becomes equal to intial string,


#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)


const ll N   =  500005;
const ll mod = 1e9 + 7;

using namespace std;

ll power(ll a, ll b,ll m)    //a is base, b is exponent
{
    if(b==0)
        return 1;
    if(b==1)
        return a%m;
    if(b%2 == 1)
        return (power(a,b-1,m)*a)%m;
    ll q = power(a,b/2,m);
    return (q*q)%m;
}

void solve(){

  ll x=0,y=0,c=0,ans,l;
  ll n,m,k;
  cin>>n>>k;
  string st;

  cin>> st;
  ll res=0,np=1,p =31;
  ll hshp[n], hshr[n];

 for (ll i = 0; i < st.size(); ++i){

     res = (res + (st[i]-'a'+1) * np) % mod;
     np  = np *p % mod;
     hshp[i] = res;
 }

 res=0;

 frr (i, 0 ,st.size()){

     res= (res * p + (st[i]-'a'+1) ) % mod;

     hshr[i] = res;
 }

 m = (n+k-1)/k;
 ans = m;
 for (ll i = 1; i <m; ++i){
   l = n - k*i-1;
   x = hshp[l];
   y = hshr[k*i];
   
   if(x==y){
    ans = i;
    break;
   }
 }
 cout << ans << "\n";

}

signed main(){
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  ll T=1;
  //cin>>T;
  while(T--){
  solve();
  }
  return 0;
}



// given a string, perform following operations : 

1. if(sz(s) == l) stop and print ans,else do continue with operations
2. break the string two parts such that new string s' = s(0,i) and  t = s(i+1,n-1)
3. Append t to s' times the operation number of previous operation.
4. s = s', and l=l+1,repeat until(l!=k)