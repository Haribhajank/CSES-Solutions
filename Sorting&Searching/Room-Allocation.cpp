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

    vector<pair<pair<int,int>,int>> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first.first>>v[i].first.second;
        v[i].second = i;
    }

    sort(all(v));
    vector<int> ans(n,0);

    priority_queue<pair<int,int>> pq;
    int rooms = 0, last_room = 0;
    for(int i=0;i<n;i++){
        if(pq.empty()){
            last_room++;
            pq.push({-v[i].first.second,last_room});
            ans[v[i].second] = last_room;
        }
        else{
            pair<int,int> mini = pq.top();
            if(-mini.first<v[i].first.first){
                pq.pop();
                pq.push({-v[i].first.second,mini.second});
                ans[v[i].second] = mini.second;
            }
            else{
                last_room++;
                pq.push({-v[i].first.second,last_room});
                ans[v[i].second] = last_room;
            }
        }
        rooms = max(rooms,(int)pq.size());
    }

    cout<<rooms<<"\n";
    print(ans);

    return 0;
}