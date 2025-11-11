#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node, int par,vector<vector<int>>& adj, vector<int>& dist){
    for(int it:adj[node]){
        if(it != par){
            dist[it] = dist[node] + 1;
            dfs(it,node,adj,dist);
        }
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> marked(k);
    for(int i=0;i<k;i++) cin>>marked[i];
    vector<int> is_marked(n+1,0);
    for(int i=0;i<k;i++) is_marked[marked[i]] = 1;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist_root(n+1,0);
    dfs(1,0,adj,dist_root);
    int node1 = 0;
    for(int i=1;i<=n;i++) if(dist_root[i] > dist_root[node1] && is_marked[i]) node1 = i;
    vector<int> dist_1(n+1,0);
    dfs(node1,0,adj,dist_1);
    int node2 = 0;
    for(int i=1;i<=n;i++) if(dist_1[i] > dist_1[node2] && is_marked[i]) node2 = i;

    vector<int> dist_2(n+1,0);
    dfs(node2,0,adj,dist_2);

    int ans = (dist_2[node1] + 1)/2;
    cout<<ans<<'\n';


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