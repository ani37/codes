#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i = a; i < n; ++i)
int main(){
 ios_base::sync_with_stdio(false);   
 cin.tie(NULL);
int t;
cin>>t;
while(t--){
	int n,m,p,q;
cin>>n>>m>>p>>q;
int a[n][m],b[p][q];
REP(i,0,n){
	REP(j,0,m){
		cin>>a[i][j];
	}}
	REP(i,0,p){
	REP(j,0,q){
		cin>>b[i][j];
	}}
if(m==p){
int c[n][q];
memset(c, 0, sizeof(c[0][0]) * n * q);
REP(i,0,n){
	REP(j,0,q){
		REP(k,0,m){
			c[i][j] +=a[i][k]*b[k][j];
		}
	}
}
REP(i,0,n){
	REP(j,0,q){
		cout<<c[i][j]<<" ";
	}
	cout<<"\n";
}
}
else if(n==q){
int c[p][m];
memset(c, 0, sizeof(c[0][0]) * p * m);
REP(i,0,p){
	REP(j,0,m){
		REP(k,0,n){
			c[i][j] +=b[i][k]*a[k][j];
		}
	}
}
REP(i,0,p){
	REP(j,0,m){
		cout<<c[i][j]<<" ";
	}
	cout<<"\n";
}
}


else cout<<"not possible"<<endl;
}
return 0;
}
