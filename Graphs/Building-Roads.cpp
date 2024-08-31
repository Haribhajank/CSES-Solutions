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

void dfs(int v,int p){
    if(vis[v]) return;
    vis[v] = 1;
    for(int c : adj[v]){
        if(c!=p){
            dfs(c,v);
        }
    }
}

signed  main() {
    make_it_fast;
 
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int count = 0;
    vector<pair<int,int>> roads;
    for(int i =0;i<n;i++){
        if(vis[i]==0){
            dfs(i,-1);
                if(i!=0){
                roads.push_back({i,i+1});
            }
            count++;
        }

    }

    cout<<count-1<<"\n";
    for(int i=0;i<roads.size();i++){
        cout<<roads[i].first<<" "<<roads[i].second<<"\n";
    }
    
    return 0;
}