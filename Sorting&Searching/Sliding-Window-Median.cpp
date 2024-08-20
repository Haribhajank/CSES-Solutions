#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_multiset ;

#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9
 
signed  main() {
    make_it_fast;
 
    int n,k;
    cin>>n>>k;

    int a[n];
    ordered_multiset os;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        if(q.size()==k){
            if(k&1){
                cout<<(*os.find_by_order(k/2)).first<<" ";
            }
            else{
                cout<<(*os.find_by_order(k/2-1)).first<<" ";
            }

            int r = q.front().first;
            q.pop();

            os.erase(os.find_by_order(os.order_of_key({r,-1})));
        }

        os.insert({a[i],i});
        q.push({a[i],i});
    }

    if(k&1){
        cout<<(*os.find_by_order(k/2)).first<<" ";
    }
    else{
       cout<<(*os.find_by_order(k/2-1)).first<<" ";     
    }
    
    return 0;
}