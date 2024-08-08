#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9
#define int long long
 
struct project{
    int startDate = 0;
    int endDate = 0;
    int reward = 0;
};
 
bool check (project a, project b){
    return a.endDate<b.endDate;
}
 
signed  main() {
    make_it_fast;
 
    ll n;
    cin>>n;
 
    vector<project> arr(n+1);
 
    for(int i=1;i<=n;i++){
        cin>>arr[i].startDate>>arr[i].endDate>>arr[i].reward;
    }
 
    sort(arr.begin()+1,arr.end(),check);
 
    vector<int> endDate(n+1);
 
    for(int i=1;i<=n;i++){
        endDate[i] = arr[i].endDate;
    }
 
    vector<int> dp(n+1,0);
 
    for(int i=1;i<=n;i++){
        int j = distance(endDate.begin(),lower_bound(endDate.begin(),endDate.end(),arr[i].startDate)) - 1;
        dp[i] = max(dp[i-1], dp[j] + arr[i].reward);
        //dp[i-1] == not doing work on ith day 
        //dp[j]+arr[i].reward == doing work on ith day getting award of that day 
        //and dp[j]==net profit if last job was before starting of this job
    }
 
    cout<<dp[n]<<"\n";
 
}