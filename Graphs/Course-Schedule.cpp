#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

const int N = 1e5+7;

vector<int> adj[N];
int vis[N];
vector<int> ans;
int flag = 0;

void dfs(int v,int p){
    vis[v] = 1;
    for(int u : adj[v]){
        if(vis[u]==1) flag = 1;
        if(vis[u]==0) dfs(u,v);
    }
    ans.push_back(v);
    vis[v] = 2;
}
 
signed  main() {
    make_it_fast;
 
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,-1);
        }
    }

    if(flag==0){
        reverse(all(ans));
        print(ans);
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    
    return 0;
}