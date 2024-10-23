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
Main principle is distance between two nodes a and b is 
depth(a) + depth(b) - depth(LCA(a,b))

*/

int n,q;
vector<int> graph[200005];
int L[200005]; // Depth of each node
int a[21][200005]; //Ancestors of each node 

//This function immediate parent and depth of each node  
void dfs(int node, int parent, int depth){
    a[0][node] = parent; // Immediate parent
    L[node] = depth; //Depth of each node

    for(int v : graph[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
} 


// Pre process ith parent for each node j
// ith parent can be found as (i-1)th parent of --> (i-1)th parent of node j
void LCA_pre(int node, int parent){
    dfs(1,-1,0);

    for(int i=1; (1<<i) <=n; i++){
        for(int j=1;j<=n;j++){
            a[i][j] = a[i-1][a[i-1][j]];
        }
    }
}

int LCA(int p, int q){
    if(L[p]<L[q]){ // Making sure the p node is deeper 
        swap(p,q);
    }

    int diff = L[p] - L[q];

    //Bringing p at the same level at q
    for(int i=20; i>=0; i--){
        if(diff & (1<<i)){
            p = a[i][p];
        }
    }

    if(p == q){
        return p;
    }

    for(int i=20; i>=0; i--){
        if(a[i][p] != a[i][q]){
            p = a[i][p];
            q = a[i][q];
        }
    }

    return a[0][p];
}

signed  main() {
    make_it_fast;

    cin>>n>>q;

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    LCA_pre(1,-1);

    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<L[x] + L[y] - (2*L[LCA(x,y)])<<"\n";
    }
    
    return 0;
}