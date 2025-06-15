#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node,vector<int>& vis,int level,vector<int>&levels, vector<vector<int>>& adj){
    vis[node] = 1;
    levels[level]++;
    for(auto it:adj[node]) if(vis[it] == 0) dfs(it,vis,level+1,levels,adj);
}

void solve(){
    int n;
    cin>>n;

    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }

    vector<int> levels(n+1,0);
    vector<int> vis(n+1,0);
    dfs(1,vis,0,levels,adj);
    int ans = 0;
    for(int i=0;i<=n;i++) ans += levels[i]%2;
    cout<<ans;

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