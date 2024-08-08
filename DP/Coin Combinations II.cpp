#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
 
int  main() {
    make_it_fast;
 
    int n,x;
    cin>>n>>x;
 
    vector<int> v(n);
 
    for(auto &x:v){
        cin>>x;
    }
 
    vector<vector<int>> dp(n+1, vector<int>(x+1,0));
 
    dp[0][0] = 1;
 
 
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(j-v[i-1]>=0){
                (dp[i][j]+= dp[i][j-v[i-1]])%=MOD;
            }
        }
    }
 
    cout<<dp[n][x]<<"\n";
 
 
}
