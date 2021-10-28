  
  //https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/
//https://www.spoj.com/problems/NAKANJ/

  #include <bits/stdc++.h>
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <cstring>
  #include <complex>
  #include <chrono>
  #define endl "\n"
  #define ll long long int
  #define vi vector<int>
  #define vll vector<ll>
  #define vvi vector < vi >
  #define pii pair<int,int>
  #define pll pair<long long, long long>
  #define mod 1000000007
  #define inf 1000000000000000001;
  #define all(c) c.begin(),c.end()
  #define mp(x,y) make_pair(x,y) 
  #define mem(a,val) memset(a,val,sizeof(a))
  #define eb push_back
  #define f first
  #define s second
  
  using namespace std;

struct  cell
{
  int x,y,dis;
  cell(){}
  cell(int x,int y,int dis) : x(x),y(y),dis(dis){}

};


  findmin(string i,string f)
  {
      int xi,yi,xf,yf;
      xi= i[0] -'a'+1;
      yi= i[1] - '0';
      xf= f[0] -'a'+1;
      yf= f[1] - '0';

      pii dxy[]={{-2,-1},{-2,1},{-1,-2},{-1,2},{2,-1},{2,1},{1,2},{1,-2}};
      queue<cell> q;
      q.push(cell(x1,y1,0));
      cell t;
      int x,y;
      int vis[9][9];
      mem(vis,0);

      while(!q.empty())
      {
          t=q.front();
          q.pop();
          if(t.x==xf and t.y==yf)
            return t.dis;
          for (int i = 0; i < 8; ++i)
          {
            x = t.x + dxy[i].first;
            y = t.y  +dxy[i].second;
            if( (x<=8 and x>=1 and y<=8 and y>=1) and !vis[x][y])
            {
                vis[x][y]=1;
                q.push(cell(x,y,t.dis+1));
            }
          }

      }
  }

   void solve()
  {     int T;
     cin>>T;
     while(T--)
     {
        string ch1,ch2;
        cin>>ch1>>ch2;
      cout<<findmin(ch1,ch2)<<"\n";   
     }
     
  }

  int main()
  {

    std::ios::sync_with_stdio(false);
      cin.tie(0);
   
      solve();
   
      
    return 0;
  }