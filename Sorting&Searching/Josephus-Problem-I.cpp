#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define print(v) for(int i=0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<"\n";
#define MOD 1000000007
#define tc(t) int t; cin >> t; while (t--)
#define all(x) (x).begin(),(x).end()
#define inf 1e9

signed main() {
    make_it_fast;

    int n;
    cin>>n;

    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }

    int flag = 0;

    while(!q.empty()){
        if(flag==0){
            int a = q.front();
            q.pop();
            q.push(a);
            flag = 1;
        }
        else{
            cout<<q.front()<<" ";
            q.pop();
            flag = 0;
        }
    }

    

    return 0;
}