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

    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   

    vector<int> dis;
    vector<int> vis;
    int parent[n+1];

    dis.assign(n+1,(int)inf);
    vis.assign(n+1,0);

    queue<int> q;
    dis[1] = 0;
    q.push(1);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        vis[a] = 1;
        for(int b : adj[a]){
            if(dis[b]==inf){
                dis[b] = dis[a]+1;
                parent[b] = a;
                q.push(b);
            }
        }
    }

    if(vis[n]==0){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout<<dis[n]+1<<"\n";
        vector<int> v;
        v.push_back(n);
        while(v.back()!=1){
            v.push_back(parent[v.back()]);
        }
        reverse(all(v));
        print(v);
    }
    
    return 0;
}