#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

int dfs_1(int node, int par,vector<vector<int>>& adj,vector<int>& arr,vector<int>& dp,vector<int>& par_arr){
    par_arr[node] = par;
    int ans = arr[node];
    for(auto it:adj[node]){
        if(it != par){
            ans += dfs_1(it,node,adj,arr,dp,par_arr);
        }
    }
    return dp[node] = max(0LL,ans);
}

void dfs_2(int node, int par, vector<vector<int>>& adj,vector<int>& arr,vector<int>& dp,vector<int>& ans_arr){
    int ans = arr[node];
    for(auto it:adj[node]) if(it != par) ans += dp[it];
    ans += max(max(0LL,ans_arr[par]) - max(0LL,ans),0LL);
    ans_arr[node] = ans;
}

void dfs(int node,int par, vector<vector<int>>& adj,vector<int>& arr,vector<int>& dp,vector<int>& ans_arr){
    dfs_2(node,par,adj,arr,dp,ans_arr);
    for(auto it:adj[node]){
        if(it != par) dfs(it,node,adj,arr,dp,ans_arr);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        int val;
        cin>>val;
        (val == 1) ? arr[i] = 1 : arr[i] = -1; 
    }
    vector<vector<int>> adj(n+1);
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans_1 = 0;
    ans_1 = arr[1];
    vector<int> dp(n+1,0);
    vector<int> par_arr(n+1,0);
    for(auto it: adj[1]) ans_1 += dfs_1(it,1,adj,arr,dp,par_arr);
    vector<int> ans(n+1,0);
    ans[1] = ans_1;

    for(auto it: adj[1]) dfs(it,1,adj,arr,dp,ans);
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    
    



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