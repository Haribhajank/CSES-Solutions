#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)

//O(n^2) Approach

int find_lis(const vector<int> &a) {
    int lis = 0;
    vector<int> dp(a.size(), 1);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) { dp[i] = max(dp[i], dp[j] + 1); }
        }
        lis = max(lis, dp[i]);
    }
    return lis;
}

 
int  main() {
    make_it_fast;
    int n;
    cin>>n;
    vector<int> v(n);
 
    for(auto &x: v){
        cin>>x;
    }
    
    //O(nlogn) Approach

    vector<int> dp(n+1,1e9);
    dp[0] = -1e9;
 
    for(int i=0;i<n;i++){
        int l = upper_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
        if(dp[l-1]<v[i] && v[i]<dp[l]){
            dp[l] = v[i];
        }
    }
 
    int ans = 0;
    print(dp);
    cout<<"\n";
 
    for(int l=0;l<=n;l++){
        if(dp[l]<1e9){
            ans = l;
        }
    }
 
    cout<<ans<<"\n";
 
}
