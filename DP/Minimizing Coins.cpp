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
 
    for(auto &i:v){
        cin>>i;
    }
 
    vector<int> dp(x+1,1e9);
 
    dp[0] = 0;  
 
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-v[j]>=0){
                dp[i] = min(dp[i], 1+dp[i-v[j]]);
            }
        }
    }
 
    dp[x]==1e9?cout<<-1:cout<<dp[x]<<"\n";
 
}
