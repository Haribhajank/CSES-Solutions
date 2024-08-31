#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9
 
const int N = 2e5+7;
const int p_max = 20;
int par[1+p_max][N];
int level[N];

int getLCA(int x,int y){
    if(level[x]<level[y]){
        swap(x,y);
    }

    for(int p = p_max;p>=0;p--){
        if(level[y]+(1<<p) <= level[x]){
            x = par[p][x];
        }
    }

    if(x==y){
        return x;
    }

    for(int p = p_max;p>=0;p--){
        if(par[p][x]!=par[p][y]){
            x = par[p][x];
            y = par[p][y];
        }
    }
    return par[0][x];
}

signed  main() {
    make_it_fast;
 
    int n,q;
    cin>>n>>q;

    for(int i=2;i<=n;i++){
        cin>>par[0][i];
    }

    for(int p =1; p<=p_max;p++){
        for(int i=1;i<=n;i++){
            par[p][i] = par[p-1][par[p-1][i]];
        }
    }

    for(int i=2;i<=n;i++){
        level[i] = level[par[0][i]] + 1;
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<getLCA(a,b)<<"\n";
    }
    
    return 0;
}