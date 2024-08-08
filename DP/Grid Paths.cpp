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
 
    vector<vector<char>> grid(n,vector<char>(n));
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
 
    vector<vector<int>> dp(n,vector<int>(n,0));
 
    dp[0][0] = 1;
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!='*'){
                int left,upper;
                (i-1>=0 && grid[i-1][j]!='*')?left = dp[i-1][j]:left=0;
                (j-1>=0 && grid[i][j-1]!='*')?upper = dp[i][j-1]:upper=0;
                (dp[i][j]+=left+upper)%=MOD;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
 
    cout<<dp[n-1][n-1]<<"\n";
}