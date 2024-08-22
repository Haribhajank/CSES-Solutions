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
vector<int> tree[N];
int depth[N];
int ans[N];

void eval_depth(int src,int par){
    int src_ans = 0;
    for(int child : tree[src]){
        if(child!=par){
            eval_depth(child,src);
            src_ans = max(src_ans,1+depth[child]);
        }
    }
    depth[src] = src_ans;
}

void maxDist(int src, int par, int par_ans){
    vector<int> prefixMax, suffixMax;

    for(int child : tree[src]){
        if(child!=par){
            suffixMax.push_back(depth[child]);
            prefixMax.push_back(depth[child]);
        }
    }

    for(int i = 1;i<prefixMax.size();i++){
        prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
    }
    for(int i = suffixMax.size()-2;i>=0;i--){
        suffixMax[i] = max(suffixMax[i],suffixMax[i+1]);
    }

    int c_no = 0;
    for(int child : tree[src]){
        if(child!=par){
            int op1 = (c_no==0) ? INT_MIN : prefixMax[c_no-1];
            int op2 = (c_no==prefixMax.size()-1) ? INT_MIN : suffixMax[c_no+1];
            int partial_ans = 1 + max({par_ans,op1,op2});

            maxDist(child,src,partial_ans);
            c_no++;
        }
    }


    ans[src] = 1 + max(par_ans, (suffixMax.empty() ? -1 : suffixMax.front()));
}
 
signed  main() {
    make_it_fast;
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    eval_depth(1,0);
    maxDist(1,0,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    
    
    return 0;
}