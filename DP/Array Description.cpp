#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
 
int  main() {
    make_it_fast;
 
    int n,m;
    cin>>n>>m;
 
    vector<int> v(n);
 
    vector<vector<int>> dp(n,vector<int>(m+1,0));
 
    int x0;
    cin>>x0;
 
    if(x0==0){
        fill(dp[0].begin(),dp[0].end(),1);
    }
    else{
        dp[0][x0] = 1;
    }
 
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
 
        if(x==0){
            for(int k=1;k<=m;k++){
                for(int j:{k-1,k,k+1}){
                    if(j>=1 && j<=m){
                        (dp[i][k]+=dp[i-1][j])%=MOD;
                    }
                }
            }
        }
        else{
            for(int k:{x-1,x,x+1}){
                if(k<=m && k>=1){
                    (dp[i][x]+=dp[i-1][k])%=MOD;
                }
            }
        }
    }
 
    ll ans = 0;
 
    for(int i=1;i<=m;i++){
        (ans+=dp[n-1][i])%=MOD;
    }
 
    cout<<ans<<"\n";
 
}
