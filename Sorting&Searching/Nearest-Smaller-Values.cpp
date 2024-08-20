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

    vector<pair<int,int>> v;

    v.push_back({0,0});

    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        while(v[v.size()-1].first>=a) v.pop_back();
        cout<<v[v.size()-1].second<<" ";
        v.push_back({a,i});
    }

    return 0;
}