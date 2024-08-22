#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

const int N = 2e5 + 7;

int vis[N];
vector<int> adj[N];
vector<int> child;

void dfs(int val){
    if(!vis[val]){
        vis[val]=1;
        for(auto u:adj[val]){
            if(!vis[u]){
                dfs(u);
                child[val]+=child[u]+1;
            }
        }
    }
}
 
signed  main() {
    make_it_fast;
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a;
        cin>>a;
        a--;
        adj[i+1].push_back(a);
        adj[a].push_back(i+1);
    }   
    child.resize(n);
    dfs(0);
    print(child);
    return 0;
}