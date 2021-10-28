#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree< ll,null_type,less<ll >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


//#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
// ll it = o_set.order_of_key(b[i]) 
//to find all elemnents less than b[i]
for mutiset
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

 X.order_of_key (k) :       Number of items strictly smaller than k .
 X.find_by_order(k) :       K-th element in a set (counting from zero).


ll main()
{
    ordered_set X;
    ll n,d,count=0,median;
    cin>>n>>d;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)    cin>>arr[i];
    
    for(ll i=0;i<n;i++)
    {
        if(i>=d)
        {
            if(d&1)  median=((X.find_by_order(d/2))->first)*2;
            else    median=((*X.find_by_order(d/2)).first+(*X.find_by_order(d/2 -1)).first);
            
            if(arr[i]>=(median))  count++;
            X.erase({arr[i-d],i-d});
        }
        X.insert({arr[i],i});
    }
    cout<<count;
}