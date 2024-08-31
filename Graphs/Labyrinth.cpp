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

    int dx[] = {0,1,0,-1};
    int dy[] = {-1,0,1,0};

    string pathdir = "LDRU";

    char grid[n][m];

    pair<int,int> start,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                start = make_pair(i,j);
            }
            else if(grid[i][j]=='B'){
                end = make_pair(i,j);
            }
        }
    }

    vector<vector<int>> parent(n,vector<int>(m,-1));

    queue<pair<int,int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));
    q.push(start);
    vis[start.first][start.second]=1;

    while(!q.empty()){
        pair<int,int> s = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            pair<int,int> p = make_pair(s.first + dx[i], s.second + dy[i]);
            if(p.first>=0 && p.first<n 
                && p.second>=0 
                && p.second<m 
                && vis[p.first][p.second]!=1 
                && grid[p.first][p.second]!='#'){
                parent[p.first][p.second] = i;
                vis[p.first][p.second] = 1;
                q.push(p);
            }
        }
    }

    if(vis[end.first][end.second]==0){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        vector<int> v;
        // v.push_back(parent[end.first][end.second]);
        while(end!=start){
            int p = parent[end.first][end.second];
            v.push_back(p);
            end = make_pair(end.first - dx[p],end.second - dy[p]);
        }
        reverse(v.begin(),v.end());
        cout<<v.size()<<"\n";
        for(int i=0;i<v.size();i++){
            cout<<pathdir[v[i]];
        }
        cout<<"\n";
    }




    return 0;
}