#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

vector<int> findFour(vector<int> &v, int x){
    unordered_map<int, vector<pair<int,int>>> s;
    int n = v.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            s[v[i]+v[j]].push_back({i+1,j+1});
        }
    }

    for(auto it : s){
        auto [sum,ind1] = it;
        int rsum = x - sum;
        if(s.count(rsum)){
            auto ind2 = s[rsum];

            for(auto c1:ind1){
                for(auto c2:ind2){
                    if( c1.first!=c2.first &&
                        c1.first!=c2.second &&
                        c1.second!=c2.first &&
                        c1.second!=c2.second ){
                        return {c1.first,c1.second,c2.first,c2.second};
                    }
                }
            }
        }
    }
    return {};

}

signed main() {
    make_it_fast;

    int n,x;
    cin>>n>>x;

    vector<int> v(n);

    for(auto &x:v){
        cin>>x;
    }


    vector<int> ans = findFour(v,x);

    if(!ans.empty()){
        for(auto &x:ans){
            cout<<x<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }

    return 0;
}