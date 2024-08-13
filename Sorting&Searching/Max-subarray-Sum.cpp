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

    int n;
    cin>>n;

    int max_here = INT_MIN, max_final = INT_MIN;


    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        max_here = max(x,max_here+x);
        max_final = max(max_final,max_here);
    }

    cout<<max_final;
    
    return 0;
}