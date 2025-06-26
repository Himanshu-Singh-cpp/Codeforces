#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> degree(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int root = -1;
    bool multiple = false;
    for(int i=1;i<=n;i++){
        if(degree[i] > 2) {
            if(root == -1) root = i;
            else multiple = true;
        }
    }
    if(multiple) {
        cout<<"No";
        return;
    }
    cout<<"Yes\n";
    if(root == -1){
        cout<<"1\n";
        for(int i=1;i<=n;i++) if(degree[i] == 1) cout<<i<<' ';
    } else {
        int cnt = count(degree.begin(),degree.end(),1);
        cout<<cnt<<'\n';
        for(int i=1;i<=n;i++) if(degree[i] == 1) cout<<root<<' '<<i<<'\n';
    }

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