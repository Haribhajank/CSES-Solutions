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
 
    vector<int> dp(x+1,0);
 
    dp[0] = 1;
 
    for(int i=1;i<=x;i++){
        for(auto c:v){
            if(i-c>=0){
                (dp[i]+=dp[i-c])%=MOD;
            }
        }
    }
 
    cout<<dp[x]<<"\n";
 
}
