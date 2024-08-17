#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
// #define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9
 
int main() {
    make_it_fast;

    multiset<int> ms;
    int n;
    cin>>n;
    int count = 0;
    while(n--){
        int x;
        cin>>x;
        auto it = ms.upper_bound(x);
        if(it==ms.end()){
            count++;
            ms.insert(x);
        }
        else{
            ms.erase(it);
            ms.insert(x);
        }
    }

    cout<<count<<"\n";

    return 0;
}