#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
 
int  main() {
    make_it_fast;
 
    int n;
    cin>>n;
 
 
    vector<int> dp(n+1,1e9);
 
    dp[0] = 0;
 
    for(int i=0;i<=n;i++){
        for(auto c: to_string(i)){
            if(i-(c-'0')>=0){
                dp[i] = min(dp[i], dp[i-(c-'0')]+1);
            }
        }
    }
 
    cout<<dp[n]<<"\n";
 
}