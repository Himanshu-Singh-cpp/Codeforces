#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> col(n+1,0);
    for(int i=1;i<=n;i++) cin>>col[i];

    vector<int> root(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto it:adj[i]){
            if(col[i] != col[it]) root[i]++, root[it]++; 
        }
    }

    int ans = -1;
    int maxi = *max_element(root.begin(),root.end());
    for(int i=1;i<=n;i++) if(root[i] == maxi) ans = i;
    // for(int i=1;i<=n;i++) cout<<root[i]<<' ';
    for(int i=1;i<=n;i++){
        if(i == ans) continue;
        for(auto it: adj[i]) if(it != ans && root[it] >= 2 && col[it] != col[i]) {
            // cout<<it<<' '<<i<<' ';
            cout<<"NO";
            return;
        }
    }

    cout<<"YES\n"<<ans;




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