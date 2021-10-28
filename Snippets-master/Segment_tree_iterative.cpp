    #include <bits/stdc++.h> 
    using namespace std;
    #define ll long long
    #define fl(i,a,b) for(ll i=a;i<b;i++)
    #define endl '\n'
    #define pb push_back
    #define ff first
    #define ss second
    #define mode 998244353 
    #define mx 300005
    #define inf 1e17
    #define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    #define end efg
    const ll N = 2e5+5;  // limit for array size
    ll n;  // array size
    ll t[2 * N];
    ll start = 300005;
    ll end = 300006;
    void build() {  // build the tree
      for (ll i = n - 1; i > 0; --i) t[i] = t[i<<1] ^ t[i<<1|1];
    }
    
    void modify(ll p, ll value) {  // set value at position p
      for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] ^ t[p^1];
    }
     
    ll query(ll l, ll r) {  // sum on llerval [l, r)
      ll res = 0;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res ^= t[l++];
        if (r&1) res ^= t[--r];
      }
      return res;
    }
     
    main()
    {
        fast;
        ll q;
        cin>>q;
        ll flag = 0;
        while(q--)
        {
            ll type;
            cin>>type;
            if(type==2 && flag==0)
            {
                type = 1;
            }
            if(type==1)
            {
                ll x;
                cin>>x;
                modify(start--,x);
                flag = 1;
            }
            else if(type == 2)
            {
                ll x;
                cin>>x;
                flag = 1;
                modify(end++,x);
            }
            else
            {
                ll x,y;
                cin>>x>>y;
            //    cout<<t[x+start+n]<<" "<<t[y+start+n]<<endl;
                cout<<query(x+start,y+start+1)<<endl;
            }
     
        }
    }