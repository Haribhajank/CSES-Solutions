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
 
    vector<int> price(n),pages(n);
 
    for(auto &x:price){
        cin>>x;
    }
 
    for(auto &x:pages){
        cin>>x;
    }
 
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
 
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(j-price[i-1]>=0){
                dp[i][j] = max(dp[i][j],pages[i-1]+dp[i-1][j-price[i-1]]);
            }
        }
    }
 
    cout<<dp[n][x]<<"\n";
 
}