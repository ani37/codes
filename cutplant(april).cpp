#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    // your code goes here
    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],b[n],ans=0;
        int i,j;
        //Input
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
 
        deque<int> q;
        int possible=1;
        //Check for case of -1 first.
        for(i=0;i<n;i++)
        {
            if(a[i]<b[i])
            {
                possible=0;
                break;
            }
        }
        if(possible==0)cout<<-1<<endl;
        else
        {
            for(i=0;i<n;i++)
            {
                while(!q.empty() and q.back()<b[i])//If there are any recently inserted plants less than b[i]
                    q.pop_back();
                while(!q.empty() and q.front()>a[i])//If height of any previous b[j] is less than current a[i].
                    q.pop_front();//Please note, that due to our prev. while loop, deque has b[i] in descending
                    //order.
                if( a[i]!=b[i] and (q.empty() or b[i]!=q.back()) )
                {
                    ans++;//We cannot find 2 equal b[i] :( . Hence, will need to do 1 more operation.
                    q.push_back(b[i]);
                }
            }
            cout<<ans<<endl;
        }
 
    }
 
    return 0;
}