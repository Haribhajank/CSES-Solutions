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

    vector<int> v;
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        mpp[x]=1,mpp[y]=0;
        v.emplace_back(x);
        v.emplace_back(y);
    }

    sort(all(v));
    int cnt = 0, cntmax = 0;
    for(int i=0;i<(2*n);i++){
        if(mpp[v[i]]){
            cnt++;
            cntmax = max(cnt,cntmax);
        }
        else{
            cnt--;
        }
    }

    cout<<cntmax;
    
    return 0;
}