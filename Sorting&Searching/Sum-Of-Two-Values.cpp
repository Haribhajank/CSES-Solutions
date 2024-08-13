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

    int n,x;
    cin>>n>>x;
    map<int,int> mpp;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(mpp.find(x-a)!=mpp.end()){
            cout<<mpp[x-a]+1<<" "<<i+1;
            return 0;
        }
        mpp[a]=i;
    }
    cout<<"IMPOSSIBLE";
    
    return 0;
}