#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

bool dfs(pair<int,int> node,pair<int,int> par,vector<vector<int>>& vis,vector<string>& col,int n,int m){
    vis[node.first][node.second] = 1;
    bool ans = false;
    for(int i=0;i<4;i++){
        int x = node.first + dx[i];
        int y = node.second + dy[i];
        pair<int,int> nbr = make_pair(x,y);
        if(x >=0 && x < n && y >=0 && y < m && par != nbr && col[node.first][node.second] == col[nbr.first][nbr.second]){
            if(vis[nbr.first][nbr.second ] == 1) return true;
            ans = ans || dfs(nbr,node,vis,col,n,m);
        } 
    }
    return ans;
}


void solve(){
    int n,m;
    cin>>n>>m;

    vector<string> col(n);
    for(int i=0;i<n;i++) cin>>col[i];

    vector<vector<int>> vis(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] == 0){
                if(dfs({i,j},{-1,-1},vis,col,n,m)){
                    cout<<"Yes";
                    return;
                }
            }
        }
    }
    cout<<"No";
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