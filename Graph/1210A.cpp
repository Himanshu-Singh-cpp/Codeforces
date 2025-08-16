#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n,vector<int>(7,0));
    for(int i=0;i<m;i++){
        int u;
        int v;
        cin>>u>>v;
        u--;v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    if(n < 7){
        cout<<m;
        return;
    } 

    int mini = INF;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int curr = accumulate(adj[i].begin(),adj[i].end(),0) + accumulate(adj[j].begin(),adj[j].end(),0);
            for(int k=0;k<7;k++) if(adj[i][k] == 1 || adj[j][k] == 1) curr--;
            mini = min(mini,curr);
        }
    }
    if(mini == INF) mini = 0;
    cout<<m - mini;
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