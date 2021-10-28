   //www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/shift-the-array-4074fac2/
    #include<bits/stdc++.h>
    #define ll          unsigned int
    #define pb          push_back
    #define eb          emplace_back
    #define c(P)        cout<<P<<"\n"
    #define pii         pair<ll,ll>
    #define mi          map<ll,ll>
    #define mii         map<pii,ll>
    #define mp(x,y)     make_pair(x,y) 
    #define mem(a,val)  memset(a,val,sizeof(a))
    #define fr(i,a,n)  for(ll i=a;i<n;i++)
    #define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n"
    const ll N=505;
    const ll mod = 1e6 + 7;
    using namespace std;
      ll adj1[N][N],adj2[N][N];
     bool vis[N][N];
  bool findpaths( ll fir,ll sec,ll h1,ll h2,ll m) 
   {   
       if(sec==0)
       {
        return false;
       }
       if((fir==h1 and sec!=h2 ) or (fir!=h1 and sec==h2))
            {
              return false;
            }
        for (ll i = 1; i <= m; ++i)
        {
         if(!vis[fir][i])
         {
          vis[fir][i] = true;
          bool ans = findpaths(adj1[fir][i],adj2[sec][i],h1,h2,m);
          if(!ans)
          {
            return ans;
          }
         }

        }
        return true;
    } 
    void solve()
    {
      ll T=1;
      cin>>T;
      while(T--)
      {  
        
      ll n,m,k,x=0,y=0,c=0,q,h1,h2;
       for (int i = 0; i <N; ++i)
       {fr(j,0,N)
        {
         adj2[i][j] = 0;
         adj1[i][j] = 0;
        }
       }
     
    cin>>m>>n>>k>>h1;   
   for (ll i = 0; i < k; ++i)
      {
      cin>>x>>y>>c;
        adj1[x][c] = y;
      }
       cin>>n>>k>>h2;
      for (ll i = 0; i < k; ++i)
      { 
      cin>>x>>y>>c;
      adj2[x][c] = y;
        
      }

       bool ans = findpaths(1,1,h1,h2,m);
       if(!ans)
       {
            cout<<"NO\n";
       }
       else cout<<"YES\n";
     
      }
     
     
    }
     
     main(){
       
            ios_base::sync_with_stdio(false);   
            cin.tie(NULL);
           solve();
    
        return 0;
        }