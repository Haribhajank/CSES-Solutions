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
Idea is to make a fenwick tree based on start and end time of the dfs 
traversal of the tree then perform point update and range sum on the fenwick tree
for answering queries , in logn time  

Important technique - To find the last significant bit - > i&-i

*/

int n,q;
int timer;
vector<int> graph[200005];
int bit[200005];
int start[200005];
int endd[200005];
int value[200005];

//Updates the Fenwick tree for all the nodes that own the node "i"  
void update(int i, int delta){
    while(i<=n){
        bit[i]+=delta;
        i+=i&-i;
    }
}


//Gives the prefix sum till index i from Fenwick tree 
int query(int i){
    int sum = 0;
    while(i>0){
        sum+=bit[i];
        i-=i&-i;
    }
    return sum;
}

//Creates a fenwick tree from the dfs traversal
void dfs(int node, int parent){
    start[node] = ++timer;
    update(timer, value[node]);

    for(int v:graph[node]){
        if(v!=parent){
            dfs(v,node);
        }
    }
    endd[node] = timer;
}

 
signed  main() {
    make_it_fast;
    
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>value[i];
    }

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1,0);

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int s,x;
            cin>>s>>x;
            update(start[s],-value[s]);
            value[s] = x;
            update(start[s],value[s]);
        }
        else{
            int s;
            cin>>s;
            cout<<(query(endd[s]) - query(start[s]-1))<<"\n";
        }
    }
   
    
    return 0;
}