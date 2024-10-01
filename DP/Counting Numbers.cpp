#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

int dp[20][10][2][2];
// question is to find the total no of numbers in the range [a,b] 
// which have no adjacent digits same 

int solve(string &R, int n, int x, int leading_zeroes, int tight){
    if(n==0){
        return 1;
    }

    if(dp[n][x][leading_zeroes][tight]!=-1) return dp[n][x][leading_zeroes][tight];

    int ub = tight ? (R[R.length() - n] - '0') : 9;
    int answer = 0;
    for(int dig = 0 ; dig <= ub ; dig++){
        if(leading_zeroes==0 && x == dig){
            continue;
        }
        answer+=solve(R, n-1, dig, leading_zeroes & (dig==0), tight & (dig==ub));
    } 
    return dp[n][x][leading_zeroes][tight] = answer;
}


 
signed  main() {
    make_it_fast;
    
        int L, R;
        cin>>L>>R;
        if(L==0){
            string r = to_string(R);
            memset(dp, -1, sizeof dp);
            cout<<solve(r,r.length(), -1, 1, 1);
        }
        else{
            if(L!=0){
                L--;
            }
            string l = to_string(L);
            string r = to_string(R);
            memset(dp, -1, sizeof dp);
            int a = solve(r, r.length(), -1, 1, 1);
            memset(dp, -1, sizeof dp);
            int b = solve(l, l.length(), -1, 1, 1);
            cout<<a-b<<"\n";
        }
          
    
    return 0;
}