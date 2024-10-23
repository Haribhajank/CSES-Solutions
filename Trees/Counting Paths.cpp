#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

int n,m;
vector<int> graph[200005];
int prefix[200005];
int L[200005];
int a[21][200005];

void dfs(int node, int parent, int depth){
    a[0][node] = parent;
    L[node] = depth;
    for(int v:graph[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}

void pre_LCA(){
    dfs(1,0,0);

    for(int i=1;(1<<i)<=n;i++){
        for(int j=0;j<=n;j++){
            a[i][j] = a[i-1][a[i-1][j]];
        }
    }
}

int LCA(int p, int q){
    if(L[p]<L[q]){
        swap(p,q);
    }

    int diff = L[p] - L[q];

    for(int i=20;i>=0;i--){
        if(diff&(1<<i)){
            p = a[i][p];
        }
    }

    if(p==q){
        return p;
    }

    for(int i=20;i>=0;i--){
        if(a[i][p]!=a[i][q]){
            p = a[i][p];
            q = a[i][q];
        }
    }

    return a[0][p];
}

void dfs_prefix_sum(int node, int parent){
    for(int v:graph[node]){
        if(v!=parent){
            dfs_prefix_sum(v,node);
            prefix[node]+=prefix[v];
        }
    }
}
 
signed  main() {
    make_it_fast;
 
     cin>>n>>m;

     for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
     }  
     pre_LCA();
     while(m--){
        int p,q;
        cin>>p>>q;
        prefix[p]++;
        prefix[q]++;
        int lca = LCA(p,q);
        prefix[lca]--;
        prefix[a[0][lca]]--;
     }

     dfs_prefix_sum(1,0);

     for(int i=1;i<=n;i++){
        cout<<prefix[i]<<" ";
     }

     cout<<"\n";
    
    return 0;
}