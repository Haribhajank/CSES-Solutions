#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e15
 
signed  main() {
    make_it_fast;
 
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<int>> g(n,vector<int>(n,inf));

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        g[a][b] = min(c,g[a][b]);
        g[b][a] = min(c,g[a][b]);
    } 

    vector<vector<int>> dis(n,vector<int>(n,0));  

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) dis[i][j] = 0;
            else if(g[i][j]) dis[i][j] = g[i][j];
            else dis[i][j] = inf; 
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(dis[a][b]==inf) cout<<-1<<"\n";
        else cout<<dis[a][b]<<"\n";
    }
    
    return 0;
}