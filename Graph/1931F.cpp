#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

bool dfs(int node,vector<int>& col,vector<set<int>>& adj){
    col[node] = 1;
    bool check = false;
    for(auto it:adj[node]){
        if(col[it] == 1) return true;
        if(col[it] == 0) check = check | dfs(it,col,adj);
    }
    col[node] = 2;
    return check;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<set<int>> adj(n);
    for(int i=0;i<m;i++){
        int u;
        cin>>u;
        int par; 
        if(n > 1){
            cin>>par;
            par--;
        }
        for(int j=2;j<n;j++){
            int u;
            cin>>u;
            u--;
            adj[par].insert(u);
            par = u;
        }
    }
    vector<int> vis(n,0);
    bool check = false;
    for(int i=0;i<n;i++){
        if(vis[i] == 0) check = check | dfs(i,vis,adj);
    }
    if(check) cout<<"No\n";
    else cout<<"Yes\n";



}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    cin >> t;
    while(t--){
        solve();
    }
}