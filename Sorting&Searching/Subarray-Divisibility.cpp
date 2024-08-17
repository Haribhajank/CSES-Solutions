#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

signed main() {
    make_it_fast;

    int n;
    cin>>n;
    vector<int> v(n);

    int psum = 0;
    v[psum] = 1;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        psum+=a;
        v[(psum%n+n)%n]++;
    }

    int ans = 0;
    for(auto x:v){
        ans+=x*(x-1)/2;
    }

    cout<<ans<<"\n";

    return 0;
}