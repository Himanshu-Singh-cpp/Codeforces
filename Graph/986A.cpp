#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    vector<int> type(n);
    for(int i=0;i<n;i++) cin>>type[i];

    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dist(n);

    for(int i=1;i<=k;i++){
        queue<pair<int,int>> qu;
        vector<int> vis(n,0);
        for(int j=0;j<n;j++){
            if(type[j] == i) qu.push({j,0}), vis[j] = 1, dist[j].push_back(0);
        }

        while(!qu.empty()){
            int node = qu.front().first;
            int curr_dist = qu.front().second;
            qu.pop();
            for(int it:adj[node]){
                if(vis[it] == 1) continue;
                dist[it].push_back(curr_dist+1);
                vis[it] = 1;
                qu.push({it,curr_dist+1});
            }
        }
    }

    for(int i=0;i<n;i++){
        sort(dist[i].begin(),dist[i].end());
        int ans = 0;
        for(int j=0;j<s;j++) ans += dist[i][j];
        cout<<ans<<' ';
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