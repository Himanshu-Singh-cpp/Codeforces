#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node,int par, vector<vector<int>>& adj, vector<int>& dist){
    dist[node] = dist[par] + 1;
    for(int it:adj[node]){
        if(it != par) dfs(it,node,adj,dist);
    }
}

void solve(){
    int n,k,c;
    cin>>n>>k>>c;

    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist_root(n+1,0);
    dist_root[0] = -1;
    dfs(1,0,adj,dist_root);

    int farthest_root = 1;
    for(int i=1;i<=n;i++) if(dist_root[i] > dist_root[farthest_root]) farthest_root = i;

    vector<int> dist_point1(n+1,0);
    dist_point1[0] = -1;
    dfs(farthest_root,0,adj,dist_point1);

    int point2 = 1;
    for(int i=1;i<=n;i++) if(dist_point1[i] > dist_point1[point2]) point2 = i;
    
    vector<int> dist_point2(n+1,0);
    dist_point2[0] = -1;
    dfs(point2,0,adj,dist_point2);

    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,max(dist_point1[i],dist_point2[i])*k - dist_root[i]*c);
    }

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