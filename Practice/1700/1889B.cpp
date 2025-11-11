#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n,c;
    cin>>n>>c;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=1;i<n;i++){
        pq.push({(i+1)*c - arr[i],arr[i]});
    }
    int curr = arr[0];
    while(!pq.empty()){
        if(pq.top().first > curr){
            cout<<"No\n";
            return;
        }
        curr += pq.top().second;
        pq.pop();
    }
    cout<<"Yes\n";

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
}