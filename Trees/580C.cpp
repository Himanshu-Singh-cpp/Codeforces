#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)

int dfs(vector<vector<int>>& adj, int node, vector<int>& vis, int cnt,int m, vector<int>& cats){
    vis[node] = 1;
    if(cats[node] == 1) cnt++;
    if(cnt > m) return 0;
    int ans = 0;
    bool leaf = true;
    for(int it: adj[node]) if(vis[it] == 0) {
        leaf = false;
        if(cats[it] == 1) ans += dfs(adj,it,vis,cnt,m,cats);
        else ans += dfs(adj,it,vis,0,m,cats);
    }
    if(leaf) ans++;
    return ans;
}
 
void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> cats(n+1,0);
    for(int i=1;i<=n;i++) cin>>cats[i];

    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector<int> vis(n+1,0);
    cout<<dfs(adj,1,vis,0,m,cats);

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin>>t;
    while (t--){
        solve();
    }
}