#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

/*
Main idea is to detect a cycle in the graph and print it 
*/
 
vector<vector<int>> graph;
vector<int> parent, color, visited;

bool dfs(int node , int par){
    visited[node] = 1;
    parent[node] = par;
    color[node] = 1;

    for(int child : graph[node]){
        /*
        This is when a cycle is detected then it backtracks the cycle 
        and pushes it in the resultant vector
        */
        if(child!=par && color[child]==1){
            vector<int> res;
            int x = node;
            while(x!=child){
                res.push_back(x);
                x = parent[x];
            }
            res.push_back(x);
            res.push_back(res[0]);
            cout<<res.size()<<"\n";
            for(auto val:res){
                cout<<val<<" ";
            }
            cout<<"\n";
            return true;
        }
        else if(child!=par && color[child]==0){
            if(dfs(child,node)) return true;
        }
    }
    color[node] = 2;
    return false;
}

signed  main() {
    make_it_fast;
 
    int n,m;
    cin>>n>>m;

    graph.resize(n+1);
    parent.resize(n+1,-1);
    color.resize(n+1,0);
    visited.resize(n+1,0);


    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(i,-1)){
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE\n";
    return 0;
}