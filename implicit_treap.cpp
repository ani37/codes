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
void range_update(pnode t,int l,int r,int val){//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);split(mid,t,R,r-l);//note: r-l!!
    t->lazy+=val; //lazy_update
    merge(mid,L,t);merge(t,mid,R);
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
        int l,r;
        cin>>l>>r;
        l--;r--;
       ll x= range_query(Treap,l,r);


        c(x);
    }
    return 0;
}