#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};

int dfs(pair<int,int> node,vector<string>& adj,vector<vector<int>>& vis,int n,int m, int cnt_good){
    if(adj[node.first][node.second] == '#' || adj[node.first][node.second] == 'B') return 0;
    vis[node.first][node.second] = 1;
    if(adj[node.first][node.second] == 'G') cnt_good++;
    for(int i=0;i<4;i++){
        int x = node.first + dx[i];
        int y = node.second + dy[i];
        if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && adj[x][y] != '#'){
            cnt_good = dfs({x,y},adj,vis,n,m,cnt_good);
        }
    }
    return cnt_good;
}

void solve(){
    int m,n;
    cin>>n>>m;
    vector<string> adj(n);
    for(int i=0;i<n;i++){
        cin>>adj[i];
    }
    bool possible = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j] == 'B'){
                if(i-1 >= 0) {
                    if(adj[i-1][j] == 'G') possible = false;
                    if(adj[i-1][j] == '.') adj[i-1][j] = '#';
                }
                if(j-1 >= 0) {
                    if(adj[i][j-1] == 'G') possible = false;
                    if(adj[i][j-1] == '.') adj[i][j-1] = '#';
                }
                if(j+1 < m) {
                    if(adj[i][j+1] == 'G') possible = false;
                    if(adj[i][j+1] == '.') adj[i][j+1] = '#';
                }
                if(i+1 < n) {
                    if(adj[i+1][j] == 'G') possible = false;
                    if(adj[i+1][j] == '.') adj[i+1][j] = '#';
                }
            }
        }
    }
    if(!possible){
        cout<<"No\n";
        return;
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) if(adj[i][j] == 'G') cnt++;
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    int rem = cnt - dfs({n-1,m-1},adj,vis,n,m,0);
    if(rem == 0){
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }

    

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