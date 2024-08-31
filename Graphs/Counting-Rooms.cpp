#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

const int N = 1e3+5;
char grid[N][N];
int vis[N][N];

int n,m;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

void dfs(int i, int j){
    if(vis[i][j]==1) return;
    vis[i][j] = 1;
    for(int k=0;k<4;k++){
        int x = dx[k] + i;
        int y = dy[k] + j;
        if(x>=0 && y>=0 && x<n && y<m){
            dfs(x,y);
        }
    }
}
 
signed  main() {
    make_it_fast;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='#'){
                vis[i][j]=1;
            }
            else{
                vis[i][j]=0;
            }
        }
    }

    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && vis[i][j]==0){
                dfs(i,j);
                count++;
            }
        }
    }

    cout<<count<<"\n";
    return 0;
}