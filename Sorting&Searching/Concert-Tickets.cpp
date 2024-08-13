#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9
 
signed  main() {
    make_it_fast;

    int n,m;
    cin>>n>>m;

    multiset<int> ms;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ms.insert(x);
    }

    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        auto it = ms.upper_bound(t);
        if(it==ms.begin()){
            cout<<-1<<"\n";
        }
        else{
            cout<<*(--it)<<"\n";
            ms.erase(it);
        }
    }
    
    return 0;
}