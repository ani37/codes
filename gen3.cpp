#include "testlib.h"
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define eb          emplace_back
#define c(P)        cout<<P<<"\n"

using namespace std;


int main(int argc, char* argv[]) {

    registerGen(argc, argv, 1);


    
    int n = 2;
    println(n);
    int m = 1000;
    while(n--){
    	
    int q = rnd.next(50000, 100000);
    
    cout << m << " " << q << '\n';
    for (ll i = 1; i <= m; ++i){
    	for (ll j = i+1;j <= m; ++j){
    	    int x = 2e8;
    	    int y = 1e9;
    		cout << i <<" " << j <<" " << rnd.next(x, y) << '\n';
    	} 
    }
    while(q--){
    	int x = rnd.next(1, m - 1);
    	int y = rnd.next(x+1,m);
    	cout << x <<" " << y << '\n';
    }
    }
}
