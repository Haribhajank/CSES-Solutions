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
Re - Rooting Technique

If we have the answer for some node (let's say node 1), how can we quickly find
the answer for its neighbours?

The key observation is that if we reroot the tree at node 1's neighbour (let's
say node 2), then

The depths of all nodes in node 2's subtree decrease by 1.
The depths of all nodes outside of its subtree increase by 1.

This gives us a nice way to transition from node 1's answer to node 2's answer
using only $n$ and the size of node 2's subtree! Observe that the change in the
answer is exactly n - 2(\text{node 2's subtree size})$.

that is ans[new_node] = ans[old_node] - no_of_nodes_in_newnode_subtree 
                        + (n - no_of_nodes_in_newnode_subtree)
i.e = ans[v] = ans[u] - dp[v] + (n - dp[v]);
*/

int n;
vector<int> graph[200005];
int dp[200005], ans[200005];

void dfs1(int node = 1, int parent = 0, int depth = 0){
    ans[1] += depth;
    dp[node] = 1;
    for(int i : graph[node]){
        if(i!=parent){
            dfs1(i,node,depth+1);
            dp[node]+=dp[i];
        }
    }
}


void dfs2(int node = 1, int parent = 0){
    for(int i:graph[node]){
        if(i!=parent){
            ans[i] = ans[node] - dp[i] + (n - dp[i]);
            dfs2(i,node);
        }
        
    }
}
 
signed  main() {
    make_it_fast;
 
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs1();
    dfs2();
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }   
    cout<<"\n";
    return 0;
    
}
