q:
   The internet speed at nits its too slow sometimes.you are doing a certain task and thought to lisen to a music in youtube.The video consumes 
   'D' amount of data in one second.The server can send data amounts N times.Due to the varying internet speed,the amount of data sent by the 
   server may vary with time.since you are busy on your task ,you want an unbuffered stream of video.so your task is to find after what second/s you
   should start watching the complete video without strucking.In i'th second the server can send Ai amount of data
   Note here D must be an integral multiple of the sum of
   of the total amount of data send by the server.
   Input

The first line contains two space-separated integers, N and D (1 ≤ n ≤ 10^5, 1 ≤ X ≤ 10^9).

The second line contains n space-separated integers, A1, A2, A3 ... An. (0 ≤ Ai ≤ 10^9)
Output
print a single integer denoting the minimum number of seconds after which you can start watching the video.
case1:
2 4
5 5
Output
1
case2:
6 2
1 2 3 3 6 8
Output
2



q3:
Recently manu came to know about some properties of factors of a number.so he thought to test their properties to know if his friends know about it.
First you have to print total factors of a number, he knew this was easy he gave another task with it,so
you have to also find the number of ordered pairs (a, b) such that a and b are factors of n and a and b are coprime.Prove manu you have better knowledge 
about the factors of a number.

Input
The first line contains one integer T (1 ≤ T ≤ 120000) — the number of queries you have to answer.

Then T lines follow.The ith line contains a single integer n (1 ≤ n ≤ 120000).
Output
Output T integers — answer to each query.
case1:
3
2
8
12
Output
2 3
4 7
6 15
factors of 2 are 2 and Ordered pairs-{1, 1}, {1, 2}, {2, 1}

factors of 8 are 4 and Ordered pairs-{1, 1}, {1, 2}, {1, 4}, {1, 8}, {2, 1}, {4, 1}, {8, 1}

Q ) find the tuple of positive integers (a,b,c) are there such that a , b and c mutually have no common factor greater than 1 and
  a(x/b + 1/c) + b(y/c + 1/a) + c(z/a + 1/b)  is an integer?
  x,y<=1e18
Q for cc)

You are given certain sets of string . You have check and find two char such that atleast one of them is equal to any char in
the string. Print 'NO' if it is impossible to find such characters.Note :The two chars should be distinct.
contain
: T  <=10
N    <=100
|S| <=1000
Test case 
:
input
2
4     
abc
cdefa
axz
bqr
4     
aa
aaa
a
aa

output
YES
a b
No (Since only a is present)

#include<bits/stdc++.h>
#define ll          long long
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


const ll N   =  500005;
const ll mod = 1e9 + 7;

using namespace std;
  ll n,m,k,x=0,y=0,c=0,q,ans=0;
  string a[N];
  char ch;
bool check(char x)
{
  std::vector<ll> cnt(26);
  c = 0;
  for (int i = 1; i <n ; ++i)
  {
       bool flag = 0;
   fr(j,0,a[i].size())
   {
   if(a[i][j]==x or a[i][j]==x)
   {
          flag = 1;
          break;
   }
   }
   if(!flag)
   {
    fr(j,0,a[i].size())
   {
  cnt[a[i][j]-'a']++;
   }
  c++;
   }
  }
  for (int i = 0; i <= n; ++i)
  {
    if(cnt[i]==c)
    {  

      ch  = i +'a';
      return 1;
    }
  }
return 0;
}

void solve()
{
 string s;
  cin>>n;
  cin>>s;
  for (int i = 1; i < n; ++i)
  {
     cin>>a[i];
     
  }
  for (int i = 0; i < s.size(); ++i)
  {
    if(check(s[i]))
    {
      c("YES");
      if(s[i]==ch)
        c(ch);
      else
      cout<<s[i]<<" "<<ch<<"\n";
      return;
    }
  }
  cout<<"NO";
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
//https://en.wikipedia.org/wiki/Wilson%27s_theorem
Q} given array of int find the count of elements which corresponds to fact(P-1) mod P=P-1.
n = 5 
6 3 10 7 14 
fact(2) = 2 mod 3 = 2
fact(6) = 720 mod 7 = 6

here ans is 2


Q}
https://codeforces.com/problemset/problem/1156/D
replace with only 1's and 0's to be valid
make it even and odd


Q}

https://www.codechef.com/COSQ2020/problems/PRGOTHAM

Here, number of remove indices can be of any size<=n (c[k])

so soln will become an n^2 dp sol for now : 
dp[i][j]  = if(s[i]==t[j]){
    if(c[i]) max(1+f(i+1,j),f(i+1,j+1));
    else (f(i+1,j+1));
}
       = else f(i+1,j);





__________________
nits local 
1. inclusion- exclusion using bitmasking : {2,3,5,7..} find count of numbers divides number x. //https://youtu.be/vPum8EqmFz0?t=2021
2. Given, the maximum bit a number can have is k and the numbers n and m . Perform the 2-th complement of the number n, m times. find the value of n after the operations.  
3. tcs codevita Bookselves see the screenshots modify 4 to some k

//idea : Find sum of squares of maximum common prefix length of all pairs of string.
Reference : https://www.codechef.com/JAN20B/problems/ENGLISH
soln: 
typedef struct TrieNode
{
    int leaf=0;
    struct TrieNode* child[26]={NULL};
}trie;

void add(string s, trie* t)
{
    trie* temp=t;
    for(int i=0;i<s.size();i++)
    {
        if(!temp->child[s[i]-'a'])
            temp->child[s[i]-'a']=new trie;
        temp=temp->child[s[i]-'a'];
        temp->leaf++;
    }
}
void solve(){

  ll x=0,y=0,c=0,ans=0;
  ll n;
  cin>>n;
  string s[n];
  trie *head=new trie;
  for (int i = 0; i < n; ++i)
  {
      cin>>s[i];
  }
  for (int i = 0; i < n; ++i)
  {
     c = 0;
     trie* temp=head;
      x  = s[i].size();
      std::vector<ll> v;
       for(char l:s[i])
    {
        if(temp->child[l-'a'])
            temp=temp->child[l-'a'];
        else break; 
         v.pb(temp->leaf);
    }
    x = 0;
    y = v.size();
    reverse(v.begin(), v.end());
    for (ll j = 0; j <y; ++j)
    {
        cout<<v[j]-x<<" ";
        ans+=(v[j]-x)*(y-j)*(y-j);
        x = max(x,v[j]); 
    }
    c("");
    add(s[i],head);
  }
  c(ans);
}
signed main(){
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  ll T=1;
  cin>>T;
  while(T--){
  solve();
  }
  return 0;
}

4.(It is given in ques for substring)
 find You are given a s. You can rearrange the characters of any substring s arbitrarily(provided the opening = closing) (but you cannot add, remove, or replace characters).
 Calculate and return the beauty of the most beautiful string you can produce. 
https://arena.topcoder.com/#/u/contests/17958/
match srm -784

5. https://oeis.org/search?q=1+5+11+23+33+57+71+103+130+170&sort=&language=english&go=Search
  
a(n) is also the sum of all parts of all partitions of all positive integers <= n into equal parts. 
void solve(){

  ll x=0,y=0,c=0,ans=0;
  ll n,m,k;
  cin>> n;

  for (ll i = n; i >= 1; --i){
     
      c =i;
      for (ll j = i*2; j <=n; j+=i){
          c +=j;
      }
      ans += c;
  }
  c(ans);
  
 
}

////find of number of pairs with minimum absolute difference in the subtree of x. 
//Queries does not contain leaf nodes.
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


const ll N   =  100005;
const ll mod = 1e9 + 7;
ll col[N], cnt[N], f[N], subtree[N], big[N];
pii ans[N];
vector<ll> g[N];
vector<pii > queries[N];
multiset<ll> active;
map<ll, ll> mp; 

void getsz(ll v, ll p) {
  subtree[v]=1;
  for(auto u:g[v])
  {
    if(u==p)
      continue;
    getsz(u, v);
    subtree[v]+=subtree[u];
  }
}

void add(ll v, ll p) //Function changes as per question, 
{
 ll x = col[v];
 active.insert(x);
 ll left = *(--active.find(x)); 
 ll right = *(++active.find(x));

 mp[abs(left - x)]++; 
 mp[abs(right - x)]++; 
 mp[abs(left - right)]--; 
 if (mp[abs(left - right)] == 0) 
        mp.erase(abs(left - right));  

  for(auto u:g[v])
  {
    if(u!=p && !big[u])
      add(u, v);
  }
}
void remove(ll v, ll p) //Function changes as per question, 
{
 ll x = col[v];
 ll left = *(--active.find(x)); 
 ll right = *(++active.find(x));
 active.erase(active.find(x));

 mp[abs(left - x)]--; 
 if (mp[abs(left - x)] == 0) 
        mp.erase(abs(left - x)); 
 mp[abs(right - x)]--; 
 if (mp[abs(right - x)] == 0) 
        mp.erase(abs(right - x)); 

  mp[abs(left - right)]++; 

  for(auto u:g[v])
  {
    if(u!=p && !big[u])
      remove(u, v);
  }
}

void compute(ll v)
{
   for(auto it : queries[v]){
    //  ll x = mp.begin()->F;
     ans[it.S]=*mp.begin();
  }
}

void dfs(ll v, ll p, ll keep){

  ll mx = -1, bigChild = -1;
  for(auto u:g[v]){

    if(u!=p && subtree[u]>mx)
      mx=subtree[u], bigChild=u;
  }
  for(auto u:g[v]){
    if(u!=p && u!=bigChild)
      dfs(u, v, 0); //Run DFS on small children and clear them
  }
  if(bigChild!=-1){
    dfs(bigChild, v, 1);
    big[bigChild]=1;
  }
  add(v, p); 
  //Now we have the information of subtree of v
  compute(v);

  if(bigChild!=-1)
    big[bigChild]=0;
  if(keep==0)
    remove(v, p);
}


void solve(){

  ll n,m,k,x,y;
  cin>>n >> m;
  active.insert(-mod); 
  active.insert(mod); 
  mp[2 * mod] = 1; 
  
  for (ll i = 1; i <= n; ++i){

  cin>>col[i];
  }
  for (ll i = 1; i < n; ++i){
   
    cin>>x>>y;
    g[x].pb(y);
    g[y].pb(x);
  }
  for(ll i=1;i<=m;i++){
    
    cin>>x >> k;
    queries[x].push_back({k, i});
  }
  getsz(1,0);
  dfs(1,0,0);
  for (ll i = 1; i <=m ; ++i)
  {
    cout<<ans[i].F<<" " << ans[i].S << '\n';
  }
}

signed main(){  
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  //ll T;cin >> T;while (T--)
  solve();
  return 0;
}
