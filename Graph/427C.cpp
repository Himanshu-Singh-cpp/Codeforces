#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node, vector<int>& vis,vector<vector<int>>& adj,stack<int>& st){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it] == 0) dfs(it,vis,adj,st);
    }
    st.push(node);
}

void dfs_rev(int node,vector<int>& vis,vector<vector<int>>& adj,vector<int>& comp){
    vis[node] = 1;
    comp.push_back(node);
    for(auto it:adj[node]){
        if(vis[it] == 0) dfs_rev(it,vis,adj,comp);
    }
}

void solve(){
    int n;
    cin>>n;

    vector<int> cost(n);
    for(int i=0;i<n;i++) cin>>cost[i];

    int m;
    cin>>m;
    vector<vector<int>> adj(n);
    vector<vector<int>> rev_adj(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    stack<int> st;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i] == 0) dfs(i,vis,adj,st);
    }

    long long ans_val = 0;
    long long ans_cnt = 1;
    vector<int> comp;
    fill(vis.begin(),vis.end(),0);

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(vis[node] == 0){
            dfs_rev(node,vis,rev_adj,comp);
            
            long long mini = 1e9;
            long long cnt = 0;
            for(int junc:comp){
                if(cost[junc] < mini){
                    mini = cost[junc];
                    cnt = 1;
                } else if(cost[junc] == mini){
                    cnt++;
                }
            }
            ans_val += mini;
            ans_cnt *= cnt;
            ans_cnt %= MOD;
            comp.clear();
        }

    }

    cout<<ans_val<<' '<<ans_cnt;

    



}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
}