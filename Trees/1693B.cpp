#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

int ans = 0;

int dfs(int node,int par,vector<vector<int>>& adj,vector<pair<int,int>>& limit){
    int cnt = 0;
    for(auto it:adj[node]) if(it != par){
        cnt += dfs(it,node,adj,limit);
    }
    if(cnt < limit[node].first){
        ans++;
        cnt = limit[node].second;
    }
    return min(cnt,limit[node].second);
}

void solve(){
    ans = 0;
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);

    for(int i=2;i<=n;i++){
        int par;
        cin>>par;
        adj[i].push_back(par);
        adj[par].push_back(i);
    }

    vector<pair<int,int>> limit(n+1);
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        limit[i] = {l,r};
    }
    dfs(1,-1,adj,limit);
    cout<<ans<<'\n';


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