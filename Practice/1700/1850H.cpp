#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

bool dfs(int node, vector<vector<pair<int,int>>>& adj,map<int,int>& coor, int curr_dist){
    coor[node] = curr_dist;
    for(auto it: adj[node]){
        if(coor.find(it.first) == coor.end()){
            if(dfs(it.first,adj,coor,curr_dist+it.second) == false) return false;
        } else {
            if(coor[it.first] != curr_dist + it.second){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].emplace_back(b,d);
        adj[b].emplace_back(a,-d);
    }
    map<int,int> coor;
    bool ans = true;
    for(int i=1;i<=n;i++){
        if(coor.find(i) == coor.end()){
            if(dfs(i,adj,coor,0) == false){
                ans = false;
            }
        }
    }
    if(ans){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }


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