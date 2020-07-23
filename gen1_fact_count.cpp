#include "testlib.h"
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define eb          emplace_back
#define c(P)        cout<<P<<"\n"

using namespace std;

std::vector<ll> vp;
void SieveOfEratosthenes() 
{ 
    vector<bool>prime(100000001,1);
  
    for (ll p=2; p*p<=100000001; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*p; i<=100000001; i += p) 
                prime[i] = false; 
        } 
    } 
    for (ll p=2; p<=100000001; p++) 
       if (prime[p]) 
          vp.pb(p); 
} 

int main(int argc, char* argv[]) {
   
     #ifndef ONLINE_JUDGE
         freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
         #endif
        SieveOfEratosthenes();
    registerGen(argc, argv, 1);

    /* Read number from command line. */
    int T = rnd.next(9, 10);
    println(T);
    while(T--)
    {
    int n = 1e5;
        n = rnd.next(n-3, n);
    println(n);
    /* n random numbers between 1 and 100 inclusive. */
    vector<int> a(n);
    int k = vp.size()-1;
    if(T%2==0)
    {
    for (int i = 0; i < n; i++)
    {
        int x = rnd.next(1, k);
        a[i] = vp[vp.size()-1-x];
    }
    }
    else
    {
      for (int i = 0; i < n; i++)
    {
        int x = rnd.next(10000, 100000000);
        a[i] = x;
    }
    }
    println(a);
   }
}
