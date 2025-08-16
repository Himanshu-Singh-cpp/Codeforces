#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

int dfs(int node, vector<vector<int>>& adj,queue<int>& qu,int curr,vector<int>& vis){
    curr++;
    vis[node] = 1;
    qu.push(node);
    for(auto it:adj[node]){
        if(vis[it] == 0) curr = dfs(it,adj,qu,curr,vis);
    }
    return curr;
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++){
        int size;
        cin>>size;
        if(size > 0){
            int u;
            cin>>u;
            u--;
            for(int j=1;j<size;j++){
                int v;
                cin>>v;
                v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }


    vector<int> ans(n,0);
    vector<int> vis(n,0);
    queue<int> qu;
    for(int i=0;i<n;i++){
        if(vis[i] == 0){
            int curr_size = dfs(i,adj,qu,0,vis);
            while(!qu.empty()){
                ans[qu.front()] = curr_size;
                qu.pop();
            }
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<' ';
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