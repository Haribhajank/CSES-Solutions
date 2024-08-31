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
 
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> adj[n+1];

    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }   

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> vis(n+1,0);
    vector<int> dis(n+1,1e18);

    q.push({0,1});
    dis[1] = 0;

    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if(vis[a]) continue;
        vis[a] = 1;
        for(auto u : adj[a]){
            auto [b,w] = u;
            if(dis[a]+w < dis[b]){
                dis[b] = dis[a]+w;
                q.push({dis[b],b});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}