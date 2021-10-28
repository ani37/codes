
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"
#define dbg(P)      cout<<P<<" "
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)

#define REP(i,n) for (int i = 1; i <= n; i++)

const ll N   =  500005;
const ll mod = 1e9 + 7;

using namespace std;
typedef vector<vector<ll> > matrix;
const int K = 6;
  ll a,b,c,n,m,k,x=0,z,y=0,q,ans=0;

matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

// computes A ^ p
matrix pow(matrix A, ll p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
ll fib(ll N)
{

    vector<ll> F1(K+1);
    F1[4] = x;
    F1[3] = y;
    F1[2] = z;
    F1[1] = (a)*z + (b)*y + (c)*x +10;
    F1[5] = 5;
    F1[6] = 1;
    matrix T(K+1, vector<ll>(K+1));

    T[1][1] =( a+1)%mod, T[1][2] = (b-a+mod)%mod,T[1][3]=(c-b+mod)%mod,T[1][4]=mod-c,T[1][5]=1;
    T[2][1] = 1,T[3][2]=1,T[4][3] =  1 ,T[5][5] =1,T[5][6] =1,T[6][6]=1;
   
      if (N == 1)
        return x;
      if (N == 2)
        return y;
       if (N == 3)
        return z;
       if (N == 4)
        return (a)*z + (b)*y + (c)*x +10;

    T = pow(T, N-4);
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % mod;
    return res;
}
void solve()
{
  cin>>x>>y>>z>>a>>b>>c>>n;

  c(fib(n));
}

signed main(){

      ios_base::sync_with_stdio(false);   
      cin.tie(NULL);
      ll T=1;
      cin>>T;
      while(T--)
      {
      solve();
      }
      return 0;
    }
