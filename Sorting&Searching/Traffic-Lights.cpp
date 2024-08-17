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

    int x,n;
    cin>>x>>n;

    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<int> ms;
    ms.insert(x);
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        auto it = s.upper_bound(p);
        auto it2 = it;
        it2--;
        ms.erase(ms.find(*it - *it2));
        ms.insert(p - *it2);
        ms.insert(*it - p);
        s.insert(p);
        cout<<(*(--ms.end()))<<" ";

    }

    return 0;
}