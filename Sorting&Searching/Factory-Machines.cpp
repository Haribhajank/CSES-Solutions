#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

const int N = 2e5; 
vector<int> v(N);
int t;

int maxt(int a){
    int sum = 0;
    for(auto p:v){
        sum+=(a/p);
        if(sum>=t){
            break;
        }
    }
    return sum;
}

signed main() {
    make_it_fast;

    int n;
    cin>>n>>t;

    v.resize(n,0);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(all(v));

    int l=1,r = v[n-1]*t;
    int ans = 0;

    while(l<=r){
        int mid = (l+r)/2;
        if(maxt(mid)>=t){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<"\n";

    return 0;
}