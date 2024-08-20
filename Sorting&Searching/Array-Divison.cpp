#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

int n,k;
vector<int> v(n);


//function to check if k or less than k subarrays are possible with max sum m
bool check(int m){
    int sub_cnt = 0, cur_sum = 0;

    for(int x:v){
        if(x>m) return false;
        if(cur_sum+x>m){
            sub_cnt++;
            cur_sum=0;
        }
        cur_sum+=x;
    }
    if(cur_sum>0) sub_cnt++;

    return sub_cnt<=k;
}

signed main() {
    make_it_fast;

    int n;
    cin>>n>>k;

    v.resize(n,0);

    for(auto &x:v){
        cin>>x;
    }

    int l =1 , r = 2e5*1e9;

    while(l<r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid; //if possible then minimize
        }
        else{
            l = mid+1; //else take bigger value
        }
    }

    cout<<l<<"\n";

    return 0;
}