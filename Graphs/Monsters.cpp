#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isSafe(int x,int y,int n,int m){
    return (x>=0 && x<n && y>=0 && y<m);
} 

char prog(pair<int,int> a, pair<int,int> b){
    if(a.second+1 == b.second) return 'R';
    else if(a.second-1 == b.second) return 'L';
    else if(a.first+1 == b.first) return 'D';
    else return 'U';
}

signed  main() {
    make_it_fast;
 
    int n,m;
    cin>>n>>m;

    vector<string> v(n);
    vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    vector<vector<int>> dista(n, vector<int>(m,INT_MAX));
    vector<vector<bool>> visa(n, vector<bool>(m,false));

    for(auto &s:v){
        cin>>s;
    }

    queue<pair<int,int>> q,qa;
    map<pair<int,int>, pair<int,int>> mpp;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='M'){
                dist[i][j] = 0;
                vis[i][j] = true;
                q.push({i,j});
            }
            else if(v[i][j]=='A'){
                dista[i][j] = 0;
                visa[i][j] = true;
                qa.push({i,j});
                mpp[{i,j}] = {i,j};
            }
        }
    }
    
    //BFS for monster distances
    while(q.size()>0){
        auto [x,y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isSafe(nx,ny,n,m) && v[nx][ny]!='#' && !vis[nx][ny]){
                dist[nx][ny] = (dist[x][y] + 1);
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }

    //BFS for the player
    while(qa.size()>0){
        auto [x, y] = qa.front();
        qa.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isSafe(nx,ny,n,m) && v[nx][ny]!='#' && !visa[nx][ny]){
                dista[nx][ny] = dista[x][y]+1;
                visa[nx][ny] = true;
                qa.push({nx,ny});
                mpp[{nx,ny}] = {x,y};
            }
        }
    }

    vector<pair<int,int>> res;
    bool flag = false;

    //Checking if distance of player is less than distance of monster
    //at boundary tiles
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(dist[i][j]>dista[i][j]){
                    //Storing the path by backtracking 
                    pair<int,int> z = {i,j};
                    while(mpp[z]!=z){
                        res.push_back({z});
                        z = mpp[z];
                    }
                    res.push_back(z);
                    flag = true;
                    break;
                }
            }
        }
        if(flag) break;
    }

    if(flag){
        cout<<"YES\n";
        int x = res.size();
        cout<<x-1<<"\n";
        reverse(all(res));
        for(int i=0;i<x-1;i++){
            char c = prog(res[i], res[i+1]);
            cout<<c;
        }
        cout<<"\n";
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}
