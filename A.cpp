    #include "bits/stdc++.h"
    using namespace std;
     
    using ll = long long;
    using ld = long double;
     
    #define _(_1, _2, _3, _4, NAME, ...) NAME
    #define f3(i, a, b, inc) for (int i = (a) - (inc < 0); (inc) > 0 ? i < (b) : i >= (b); i += (inc))
    #define f2(i, a, b) f3(i, a, b, 1 - 2 * (a > b))
    #define f1(i, n) f2(i, 0, n)
    #define f0(i) f2(i, 0, n)
    #define fr(...) _(__VA_ARGS__, f3, f2, f1, f0)(__VA_ARGS__)
    #define trav(i, x) for (auto& i : x)
    #define sz(x) ((int)x.size())
    #define len(x) ((int)x.length())
    #define ff first
    #define ss second
    #define pb push_back
    #define eb emplace_back
    #define all(x) begin(x), end(x)
     
    const int N = 1000001;
    const ll INF = 2e18;
    template <class T>
    bool ckmax(T& a, const T& b) {
      return a < b ? a = b, 1 : 0;
    }
    template <class T>
    bool ckmin(T& a, const T& b) {
      return b < a ? a = b, 1 : 0;
    }
    int tests = 1;ld start;
    void prep(),solve();
    int main() {
        ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);cout<<fixed<<setprecision(10);
        prep();
        for (int i = 1; i <= tests; ++i){
            //if(!ONLINE_JUDGE) cerr << "While solving TC " << i << ":\n", start = clock(); 
            solve(); 
           // if(!ONLINE_JUDGE) cerr << "TC " << i << " done in:: " << 1000 * (clock()-start) / CLOCKS_PER_SEC << " ms\n";
        }
       
    }
     
    void prep(){
        cin >> tests;
    }
    int n,k;
    string s;
    void solve(){
        cin >> n >> k >> s;
        int cnt[26] = {0};
        trav(i,s) cnt[i-'a']++;
        set<int> st;
        for(int j = 1; j <= sqrt(k) ; j++){
            if(k%j) continue;
            st.insert(j);
            st.insert(k/j);
        }
        int ans = 0;
        for(auto col:st){
            int low = 1 , high = 100000 , ansh = 0;
            while(low and low <= high){
                int mid = (low+high)/2;
                int colcnt = 0;
                fr(i,26){
                    colcnt = colcnt + cnt[i]/mid;
                }
                if(colcnt>=col){
                    ckmax(ansh,mid);
                    low = mid+1;
                }
                else
                    high = mid-1;
            }
            ckmax(ans,col*ansh);
        }
        cout << ans << "\n";
    }