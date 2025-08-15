#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node,vector<int>& vis,vector<set<int>>& adj){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it] == 0) dfs(it,vis,adj);
    }
}

void solve(){
    vector<set<int>> adj(26);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int len = s.length();
        for(int j=0;j<len;j++){
            for(int k=0;k<len;k++){
                adj[s[j]-'a'].insert(s[k]-'a');
            }
        }
    }
    int ans = 0;
    vector<int> vis(26,0);
    for(int i=0;i<26;i++){
        if((vis[i] == 0) && (adj[i].size() != 0)){
            dfs(i,vis,adj);
            ans++;
        }
    }
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