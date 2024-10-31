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
Question is given a graph of n nodes and m paths find the total no of ways to
reach from node 1 to node n (Give answer MOD 10^7)


Idea  -> dp[v] (is total path ending at node v) 
         dp[v] = Summation(dp[u]) where there is a path from u to v;
*/
 
int n,m;
vector<int> edge[100007], backedge[100007];
int dp[100007], indegree[100007];

signed  main() {
    make_it_fast;
 
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b); // Forward path 
        backedge[b].push_back(a); //Backwardd path 
        indegree[b]++; 
    }

    dp[1] = 1;

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //Kahn's Algo ??

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int next : edge[node]){
            indegree[next]--;
            if(indegree[next]==0){
                q.push(next);
            }
        }

        for(int prev : backedge[node]){
            dp[node] = (dp[node] + dp[prev])%MOD;
        }
    }

    cout<<dp[n]<<"\n";

    
    return 0;
}
