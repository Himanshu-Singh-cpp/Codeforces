#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node, int par,int curr,vector<vector<pair<int,int>>>& adj, vector<int>& weights,int stop, bool should_stop){
    if(node == stop && should_stop) return;
    weights[node] = curr;
    for(auto it:adj[node]){
        if(it.first != par){
            dfs(it.first,node,(curr^it.second),adj,weights,stop,should_stop);
        }
    }
}

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    a--;
    b--;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> weights_source(n,-1);
    dfs(a,-1,0,adj,weights_source,b,true);
    
    vector<int> weights_dest(n,-1);
    dfs(b,-1,0,adj,weights_dest,a,false);

    map<int,int> w_s;
    for(int i=0;i<n;i++){
        if(weights_source[i] == -1) continue;
        if(w_s.find(weights_source[i]) == w_s.end()){
            w_s[weights_source[i]] = 1;
        } else {
            w_s[weights_source[i]]++;
        }
    }

    for(int i=0;i<n;i++){
        if(i == b) continue;
        if(w_s.find(weights_dest[i]) != w_s.end()){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";


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