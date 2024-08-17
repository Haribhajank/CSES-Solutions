#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
// #define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9
 
int main() {
    make_it_fast;

    int n;
    cin>>n;

    vector<int> v(n);
    for(auto &x:v){
        cin>>x;
    }

    map<int,int> mpp;

    int l = 0, r =  0;
    int count = 0;
    while(r<n){
        if(mpp.find(v[r])==mpp.end()){
            mpp[v[r]]=r;
        }
        else{
            if(mpp[v[r]]>=l){
                l=mpp[v[r]]+1;
            }
            mpp[v[r]]=r;
        }
        count = max(count,r-l+1);
        r++;
    }

    cout<<count<<"\n";


    return 0;
}