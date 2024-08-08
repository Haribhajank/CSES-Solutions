#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)

int solve(int i, int j, int arr[], vector<vector<int>> &dp){
    if(i==j){
        return 0;
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;
    for(int k=i;k<j;k++){
        mini = min(mini, f(i,k,arr,dp) + f(k+1,j,arr,dp) + arr[i-1]*arr[k]*arr[j]);
    }
    
    return dp[i][j] = mini;
}

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int i = 1;
        int j = N-1;
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        
        return solve(i,j,arr,dp);
    }
};
 
int  main() {

 
}