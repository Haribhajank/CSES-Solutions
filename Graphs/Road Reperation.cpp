#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

int lin[100007], siz[100007];


/*
Question is to find the total cost of repairing the min road possible 
to connect all cities by atleast some road  - Standard min spanning tree

Idea - While making min spanning tree - keep adding the reperation cost while 
        adding a new edge

To count for the impossible case , for a succesful min spanning tree , no of times 
edge added  = n -1;
If not  = n-1 , min spanning tree is not made properly 
*/

int find(int x){
    while(x!=lin[x]){
        x = lin[x];
    }
    return x;
}

bool same(int a,int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(siz[a]<siz[b]) swap(a,b);
    siz[a]+=siz[b];
    lin[b] = a;
}
 
signed  main() {
    make_it_fast;
 
    int n,m;
    cin>>n>>m;

    vector<pair<int,pair<int,int>>> edge;

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }   

    sort(all(edge));

    for(int i=1;i<=n;i++) lin[i] = i;
    for(int i=1;i<=n;i++) siz[i] = 1;

    int total = 0;
    int count = 0;
    for(auto [c,p] : edge){
        int a = p.first;
        int b = p.second;
        if(!same(a,b)){
            unite(a,b);
            count++;
            total+=c;
        }
    }


    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(lin[i]);
    }

    if(count==n-1){
        cout<<total<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    
    return 0;
}