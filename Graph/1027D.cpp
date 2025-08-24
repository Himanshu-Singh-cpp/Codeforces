#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

int dfs(int node, vector<int>& vis,vector<vector<int>>& adj, vector<int>& cost, int curr,vector<int>& indegree){
    vis[node] = 1;
    curr = min(curr, cost[node]);

    for(auto it:adj[node]){
        if(vis[it] == 0 && indegree[it] > 0){
            curr = min(curr,dfs(it,vis,adj,cost,curr,indegree));
        }
    }   
    return curr;


}

void solve(){
    int n;
    cin>>n;

    vector<int> cost(n);
    for(int i=0;i<n;i++) cin>>cost[i];

    vector<int> indegree(n,0);
    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        v--;
        indegree[v]++;
        adj[i].push_back(v);
    }

    queue<int> qu;
    for(int i=0;i<n;i++) if(indegree[i] == 0) qu.push(i);

    while(!qu.empty()){
        int node = qu.front();
        qu.pop();

        for(auto it:adj[node]){
            if(indegree[it] > 0){
                indegree[it]--;
                if(indegree[it] == 0) qu.push(it);
            }
        }
    }

    vector<int> vis(n,0);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(indegree[i] > 0 && vis[i] == 0){
            ans += dfs(i,vis,adj,cost,cost[i],indegree);
        }
    }
    cout<<ans<<'\n';
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