
#include<bits/stdc++.h>
#define ll long long
#define pb  push_back
#define eb  emplace_back
#define c(P) cout<<P<<"\n"
#define mp(x,y) make_pair(x,y) 
#define mem(a,val) memset(a,val,sizeof(a))
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define  f first
#define  s second
#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n"
ll N=500005;
const ll mod = 43;

using namespace std;
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
// Function to find modulo inverse of a 
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
       return -1;
    else
    { 
        // m is added to handle negative x 
        ll res = (x%m + m) % m; 
       return res;
    } 
}  
  
// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
pair<ll,ll> point_addition(pair<ll,ll>x,pair<ll,ll>y,ll a)
{
   pair<ll,ll> ans;
ll lamda;
  if(x.f == y.f and x.s ==y.s)
  {
   lamda = (3*(x.f)*(x.f)+ a);
   lamda%=mod;
   ll inv = modInverse(2*x.s,mod);
   lamda = (lamda*inv)%mod;
   ans.f = (( lamda *lamda -2*x.f) + 100000000*mod)%mod;
   ans.s = ( lamda *(x.f - ans.f) -x.s + 100000000*mod)%mod;
  }
  else 
  { 
    if(x.f==0 and x.s==0)
    {
      ans = y;
      return ans;
    }
    if(y.f==0 and y.s==0)
    {
      ans = x;
      return ans;
    }
   lamda = (y.s - x.s);
   lamda%=mod;
    ll px = (y.f - x.f);
    ll inv = modInverse(px,mod);
   lamda = (lamda*inv)%mod;
   ans.f = (lamda*lamda - x.f - y.f +  100000000*mod) %mod;
   ans.s = (lamda*(x.f - ans.f) - x.s +  100000000*mod) %mod;
  }
return ans;
}
pair<ll,ll> point_mult(pair<ll,ll>x,ll k,ll a)
{    
   pair<ll,ll> ans;
   ans.f =-100000;
   ans.s =-100000;
  while(k)
  {

   if(k%2==0)
   {
   k/=2;
   x = point_addition(x,x,a);
  //   cout<<x.f<<" "<<x.s<<"\n";

   }
   else 
   {
    k= k -1;
    if(ans.f==-100000 and ans.s==-100000)
    {
      ans = x;
    }
    else
    ans = point_addition(ans,x,a);
   }
  }
 
return ans;
}
  ll power(ll a, ll b)  //a is base, b is exponent
  {
    if(b==0)
      return 1;
    if(b==1)
      return a;
    if(b%2 == 1)
      return (power(a,b-1)*a)%mod;
    ll q = power(a,b/2);
    return (q*q)%mod;
  }




void solve()
{
  ll T=1;
  //cin>>T;
  while(T--)
  {
  ll n,m,k,x=0,y=0,c=0,q,ans=0,pmx,pmy,p,a,b;
//m is message
  // G is generator
  // e1 and e2 are encripted data
  // d2 is the decripted data
  pair<ll,ll> g,pm,pb,e1,e2,px,d1,d2;
  cout<<"Input the values of m for message and a,b for eqaution y ^2 = x^3 + ax + b mod p\n\n";
  cin>>m>>a>>b;
for (int i = 0; i < 10; ++i)
{
  pm.f = (10*m + i);

  x = ((((pm.f*pm.f)%mod)*pm.f)%mod + (a*pm.f)%mod + b)%mod;
  y = (mod -1)/2; 

  if(power(x,y)==1)
  {   
     y = (mod+1)/4; 
    pm.s = power(x,y);
  break;

  }
}

// plain msg represented as elliptic curve coardinate..
//cout<< pm.f<<" "<<pm.s<<"\n";
  p = 19; // private key
  g.f= 9; 
  g.s=16;
  k=6;    //random number
   
  pb = point_mult(g,p,a); //public key of reciever
     
   px = point_mult(pb,k,a);//
   if(px.f==pm.f)
    cout<<"FUCK";
   e1 = point_mult(g,k,a);
   e2 = point_addition(px,pm,a);  
   p = 19;
   d2 = point_mult(e1,p,a);
   cout<<d2.f<<" "<<d2.s<<"\n";

   d2.s=-d2.s;
  d1 = point_addition(e2,d2,a);
  cout<<"Encripted data: {{ "<<e1.f<<" , "<<e1.s<<" } "<<", { "<<e2.f<<" , "<<e2.s<<" }}\n";
cout<<"Decripted data: {"<<d1.f<<","<<d1.s<<"}\n"; 
cout<<"Message : "<<d1.f /10<<"\n";

 }
}

    int main(){
      #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);   
        cin.tie(NULL);
       solve();
    return 0;
    }
