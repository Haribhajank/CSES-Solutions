#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e15

const int N = 1e5+7;
vector<vector<pair<int,int>>> s(N),r(N); 
vector<int> vis(N,0);

vector<int> min_path(int n,int start,vector<vector<pair<int,int>>> &s){
    vector<int> distance(n,inf);
    distance[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,start});
    while(!q.empty()){
        int v = q.top().second;
        q.pop();
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto u : s[v]){
            auto [b,w] = u;
            if(distance[v]+w < distance[b]){
                distance[b] = distance[v]+w;
                q.push({distance[b], b}); 
            }
        }
    }
    return distance;
}
 
signed  main() {
    make_it_fast;
 
    int n,m;
    cin>>n>>m;

   
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        s[a].push_back({b,c});
        r[b].push_back({a,c});
    }

    vector<int> dists = min_path(n,0,s);
    vis.assign(n,0);
    vector<int> distr = min_path(n,n-1,r);
    int tot_min = inf;
    for(int i=0;i<n;i++){
        for(auto u : s[i]){
            auto [b,w] = u;
            if(dists[i] == inf || distr[b] == inf) continue;
            tot_min = min(tot_min, dists[i] + (w/2) + distr[b]);
        }
    }

    cout<<tot_min<<"\n";


    return 0;
}