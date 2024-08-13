#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9
 
signed  main() {
    make_it_fast;

    int n,m,k;
    cin>>n>>m>>k;

    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    sort(a,a+n);
    sort(b,b+m);

    int ans = 0;
    for(int i=0,j=0;i<n;i++){
        while(j<m && b[j]<a[i]-k){
            j++;
        }
        if(j<m && b[j]<=a[i]+k){
            ans++,j++;
        }
    }

    cout<<ans<<"\n";
    
    return 0;
}