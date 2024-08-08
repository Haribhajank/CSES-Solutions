#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
 
int  main() {
    make_it_fast;
 
    int a,b;
    cin>>a>>b;
 
    vector<vector<int>> dp(a+1,vector<int>(b+1,1e9));
 
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==j) dp[i][j] = 0;
            else{
                for(int k=1;k<i;k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                }
                for(int k=1;k<=j;k++){
                    dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
                }
            }
        }
    }
 
    cout<<dp[a][b]<<"\n";
 
}
