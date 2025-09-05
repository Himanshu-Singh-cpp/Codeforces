#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    int n;
    cin>>n;

    vector<int> parent(n+1,0);
    vector<int> respect(n+1,0);
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++){
        int par;
        cin>>par;
        if(par != -1){
            adj[i].push_back(par);
            adj[par].push_back(i);
        }
        parent[i] = par;
        cin>>respect[i];
    }

    vector<int> rem;

    for(int i=1;i<=n;i++){
        int node = i;
        bool child_respect = false;
        for(int child: adj[node]){
            if(child != parent[node] && respect[child] == 0){
                child_respect = true;
                break;
            }
        }
        if(child_respect) continue;
        if(respect[node] == 1 && parent[node] != -1) rem.push_back(node);
    }
    sort(rem.begin(),rem.end());
    for(int i=0;i<rem.size();i++) cout<<rem[i]<<' ';
    if(rem.size() == 0) cout<<"-1";
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