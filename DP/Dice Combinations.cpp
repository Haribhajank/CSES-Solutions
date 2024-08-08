#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
 
int  main() {
    make_it_fast;
 
    ll n;
    cin>>n;
 
 
    vector<ll> dp(n+1,0);
 
    dp[0] = 1;
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6 && i-j>=0;j++){
            (dp[i]+=dp[i-j])%=MOD;
        }
    }
 
    cout<<dp[n]<<"\n";

}
 
