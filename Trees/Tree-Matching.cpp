#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9
const int N = 2e5+7;

vector<int> tree[N];
int dp[N][2];

void dfs(int v,int p){
    for(int child : tree[v]){
        if(child!=p){
            dfs(child,v);
            dp[v][0]+=max(dp[child][0], dp[child][1]);
        }
    }

    for(int child : tree[v]){
        if(child!=p){
            dp[v][1] = max(dp[v][1] , dp[child][0] + 1 + dp[v][0] - max(dp[child][0],dp[child][1]));
        }
    }
}
 
signed  main() {
    make_it_fast;
 
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0,-1);
    cout<<max(dp[0][0],dp[0][1])<<"\n";
    
    return 0;
}