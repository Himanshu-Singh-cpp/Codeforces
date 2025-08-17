#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int maxi = 0;
    int node = -1;
    for(int i=0;i<n;i++){
        if(adj[i].size() > maxi){
            maxi = adj[i].size();
            node = i;
        }
    }
    vector<pair<int,int>> ans;
    queue<int> qu;
    qu.push(node);
    vector<int> vis(n,0);
    vis[node] = 1;
    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto it:adj[curr]){
            if(vis[it] == 0){
                qu.push(it);
                vis[it] = 1;
                ans.push_back({curr,it});
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<(ans[i].first+1)<<' '<<(ans[i].second+1)<<'\n';
    }
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