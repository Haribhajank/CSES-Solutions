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
vector<int> adj[N];
pair<int,int> md = make_pair(-1,-1);

void dfs(int v,int f = -1,int d = 0){
    md = max(md,{d,v});

    for(auto u:adj[v]){
        if(u!=f){
            dfs(u,v,d+1);
        }
    }
}

int diameter(vector<int> adj[]){
    dfs(0);
    int first_ind = md.second;
    md = make_pair(-1,-1);
    dfs(first_ind);
    return md.first;
}
 
signed  main() {
    make_it_fast;
 
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int p,q;
        cin>>p>>q;
        p--,q--;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    int ans = diameter(adj);
    cout<<ans<<"\n";

    
    return 0;
}