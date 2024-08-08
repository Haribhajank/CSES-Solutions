#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
 
int  main() {
    make_it_fast;
 
    string a,b;
    cin>>a>>b;
 
    int n = a.size();
    int m = b.size();
 
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
 
    dp[0][0] = 0;
 
    for(int i=1;i<=m;i++){
        dp[0][i] = i;
    }
 
    for(int i=1;i<=n;i++){
        dp[i][0] = i;
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = min({1+dp[i][j-1], 1+dp[i-1][j], (a[i-1]!=b[j-1])+dp[i-1][j-1]});
        }
    }
 
    cout<<dp[n][m]<<"\n";
 
}
