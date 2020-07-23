#include "testlib.h"
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define eb          emplace_back
#define c(P)        cout<<P<<"\n"

using namespace std;


int main(int argc, char* argv[]) {

    registerGen(argc, argv, 1);

    /* Read number from command line. */

    
    int n = 2;
    println(n);
    int m = (2000)/n;
    while(n--){
    	
    int q = rnd.next(500000, 1000000);
    cout << m << " " << q << '\n';
    for (ll i = 1; i <= m; ++i){
    	for (ll j = i+1;j <= m; ++j){
    		cout << i <<" " << j <<" " << rnd.next(2e6, 1e9) << '\n';
    	} 
    }
    while(q--){
    	int x = rnd.next(1, m - 1);
    	int y = rnd.next(x+1,m);
    	cout << x <<" " << y << '\n';
    }
    }
}
