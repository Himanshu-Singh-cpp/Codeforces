#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node, int parent,vector<int>&par, vector<vector<int>>& adj){
    par[node] = parent;
    for(auto it:adj[node]) if(it != parent) dfs(it,node,par,adj);
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> t(n+1,0);
    set<int> broken;
    
    for(int i=0;i<n-1;i++){
        int u,v,t;
        cin>>u>>v>>t;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(t == 2) broken.insert(u), broken.insert(v);
    }

    vector<int> par(n+1,0);
    dfs(1,0,par,adj);
    vector<int> vis(n+1,0);

    for(int i=1;i<=n;i++){
        if(broken.find(i) != broken.end()){
            int node = i;
            while(node != 1 && vis[node] == 0){
                vis[node] = 1;
                int parent = par[node];
                if(broken.find(parent) != broken.end()) broken.erase(parent);
                node = par[node];
            }
        }
    }

    cout<<broken.size()<<'\n';
    for(auto it : broken) cout<<it<<' ';


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