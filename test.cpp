  #include <bits/stdc++.h>
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <cstring>
  #include <chrono>
  #include <complex>
  #define endl "\n"
  #define ll long long int
  #define vi vector<int>
  
  using namespace std;
  int main()
  {
    std::ios::sync_with_stdio(false);
    int T = 1;
    //cin>>T;
    // cin.ignore(); must be there when using getline(cin, s)
    while(T--)
    {
      ll n,ans=LONG_MAX;
      cin>>n;
      ll arr[n] , brr [n];
      for(ll i=0;i < n; i++){
        cin >> arr[i];
      }
      for(ll i=0;i < n; i++){
        cin >> brr[i];
      }
      for(ll i=0;i < n; i++){
        ans = min(ans,brr[i]/arr[i]);
      }
      cout << ans << "\n";
    }
    return 0;
  }





#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define ll long long int

#define s second

using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    while(T--)
    {
        ll n,ans=0;
        cin>>n;
        ll x = n, y = n;
        ll a[n];
        ll b[n];

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a,a+n);
    reverse(a,a+n);
     for (int i = 0; i < n; ++i)
        cin >> b[i];
    sort(b,b+n);
    reverse(b,b+n);
    while(x>0){

        if(a[x-1] > b[y-1]){
            ans++;
            x--;y--;
        }
        else{
            x--;  
        }
    }
    cout<<ans<<"\n";
    }
    return 0;
}
