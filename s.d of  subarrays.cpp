#include<bits/stdc++.h>
using namespace std;

vector<double> A(1000001);
vector<double> pref(1000001);
vector<double> prefsq(1000001);
int n, k;
int main(){
  int T=1;
 // cin>>T;
  while(T--)
  {

        ios_base::sync_with_stdio(false);   
        cin.tie(NULL);
  cin>>n>>k;
  for(int i=0;i<n;i++)cin>>A[i];
  pref[0]=A[0];
  prefsq[0]=A[0]*A[0];
  
  for(int i=1;i<n;i++){
    pref[i]=A[i]+pref[i-1];
    prefsq[i]=A[i]*A[i] + prefsq[i-1];  
  }
  
  double cur=abs(pref[k-1]/k - sqrt( prefsq[k-1] / k - (pref[k-1]/k)*(pref[k-1]/k)) );

  for(float i=0;i<=n-k;i++){
    
  cout<<fixed<<setprecision(12)<<( sqrt( ((prefsq[i+k-1]-prefsq[i-1])/k) - ((pref[i+k-1]-pref[i-1])/k)*((pref[i+k-1]-pref[i-1])/k)) )<<" ";
  }
}  
}
