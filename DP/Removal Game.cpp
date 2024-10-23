#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9


 
signed  main() {
    make_it_fast;
 
    int n;
    cin>>n;

    vector<int> v(n);
    for(int &i:v){
        cin>>i;
    }   

    int sum = accumulate(v.begin(),v.end(),0LL);

    vector<vector<int>> dp(n, vector<int>(n,-1e18));

    for(int l = n-1;l>=0;l--){
        for(int r = l;r<n;r++){
            if(l==r) dp[l][r] = v[l];
            else{
                dp[l][r] = max({dp[l][r], v[l] - dp[l+1][r], v[r] - dp[l][r-1]});
            }
        }
    }

    cout<<(dp[0][n-1] + sum)/2;
    
    return 0;
}