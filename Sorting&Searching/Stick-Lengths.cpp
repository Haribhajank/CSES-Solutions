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

    vector<int> v(n);

    for(auto &x:v){
        cin>>x;
    }

    sort(all(v));

    int m = (n+1)/2;
    m--;
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=abs(v[i]-v[m]);
    }
    
    cout<<ans<<"\n";
    return 0;
}