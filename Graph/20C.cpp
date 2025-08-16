#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e11
#define MOD (int)(1e9+7)


void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        a--;
        b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,INF);
    dist[0] = 0;
    pq.push({0,0});
    vector<int> par(n,-1);
    while(!pq.empty()){
        int curr_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(curr_dist > dist[node]) continue;
        for(auto it: adj[node]){
            if(curr_dist + it.second < dist[it.first]){
                pq.push({curr_dist + it.second,it.first});
                dist[it.first] = curr_dist + it.second;
                par[it.first] = node;
            }
        }
    }
    if(dist[n-1] == INF){
        cout<<"-1";
        return;
    }
    int curr = n - 1;
    vector<int> ans;
    while(curr != -1){
        ans.push_back(curr+1);
        curr = par[curr];
    }
    reverse(ans.begin(),ans.end());
    for(auto it: ans) cout<<it<<' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    // cin >> t;
    while(t--){
        solve();
    }
}