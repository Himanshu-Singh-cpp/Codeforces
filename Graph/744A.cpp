#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

int dfs(int node, vector<vector<int>>&adj,vector<int>&vis, int curr){
    vis[node] = 1;
    curr++;
    for(auto it:adj[node]){
        if(vis[it] == 0) curr = dfs(it,adj,vis,curr);
    }
    return curr;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> gov(k);
    for(int i=0;i<k;i++) cin>>gov[i];
    for(int i=0;i<k;i++) gov[i]--;

    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n,0);
    vector<int> sizes;
    for(int i=0;i<k;i++){
        int size = dfs(gov[i],adj,vis,0);
        sizes.push_back(size);
    }
    
    long long ans = -m;
    for(long long size:sizes){
        ans += (size*(size-1))/2;
    }
    int maxi = *max_element(sizes.begin(),sizes.end());
    int left = count(vis.begin(),vis.end(),0);
    while(left > 0){
        ans += maxi;
        maxi++;
        left--;
    }
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