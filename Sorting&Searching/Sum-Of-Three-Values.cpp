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
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i+1;
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        int l=0, r=n-1;
        while (l < r) {
            int target = x - v[i].first;
            if (l != i && r != i && v[l].first + v[r].first == target) {
                cout << v[i].second << " " << v[l].second << " "<< v[r].second;
                return 0;
            }
            if (v[l].first + v[r].first < target) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout<<"IMPOSSIBLE";
    return 0;
}