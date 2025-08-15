#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void dfs(int node, int node_col, vector<vector<int>>& adj, vector<int>& col){
    col[node] = 1 - node_col;
    for(auto it:adj[node]){
        if(col[it] == -1) dfs(it,1-node_col,adj,col);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> col(n,-1);
    dfs(0,1,adj,col);
    long long zero = count(col.begin(),col.end(),0);
    long long one = n - zero;
    long long ans = one*zero-(n-1);
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