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

    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].second>>v[i].first;
    }

    sort(all(v));

    int count = 0;
    int currM = -1;
    for(int i=0;i<n;i++){
        if(currM<=v[i].second){
            count++;
            currM = v[i].first;
        }
    }

    cout<<count<<"\n";

    return 0;
}