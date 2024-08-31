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
    vector<int> color(n+1,-1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   

    queue<int> q;
    bool is_bi = true;

    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            q.push(i);
            color[i] = 0;
        }
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(int u : adj[v]){
                if(color[u]==-1){
                    color[u] = color[v] ^ 1;
                    q.push(u);
                }
                else{
                    is_bi &= (color[u] != color[v]);
                }
            }
        }
    }

    if(!is_bi){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<color[i]+1<<" ";
        }
        cout<<"\n";
    }

    
    return 0;
}