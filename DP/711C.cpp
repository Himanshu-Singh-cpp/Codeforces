#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e12
#define MOD (int)(1e9+7)
 
void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    // n -> number of trees
    // m -> number of colors
    // k -> beauty of the resulting color

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<int>> paint(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++) cin>>paint[i][j];
    }

    // dp[i+1][j][k] -> cost of beauty k, till index i, having j as the color at ith index
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+2,INF)));
    for(int j=1;j<=m;j++) dp[0][j][0] = 0;
    
    for(int i=0;i<n;i++){
        for(int l=0;l<=k;l++){
            if(arr[i] == 0) {
                for(int j=1;j<=m;j++){
                    if(i != 0) dp[i+1][j][l] = min(dp[i+1][j][l], dp[i][j][l] + paint[i][j]);
                    for(int p=1;p<=m;p++) if(p != j || i == 0) dp[i+1][j][l+1] = min(dp[i+1][j][l+1], dp[i][p][l] + paint[i][j]);
                }    
            } else {
                if(i != 0) dp[i+1][arr[i]][l] = min(dp[i+1][arr[i]][l],dp[i][arr[i]][l]);
                for(int p=1;p<=m;p++) if(p != arr[i] || i == 0) dp[i+1][arr[i]][l+1] = min(dp[i+1][arr[i]][l+1], dp[i][p][l]);
            }
        }
    }
    int ans =  INF;
    // for(int i=0;i<=n;i++){
    //     for(int l=0;l<=k;l++){
    //         for(int j=0;j<=m;j++) cout<<dp[i][j][l]<<' ';
    //         cout<<'\n';
    //     }
    //     cout<<'\n';
    // }
    for(int j=1;j<=m;j++) ans = min(ans,dp[n][j][k]);
    if(ans == INF) cout<<"-1";
    else cout<<ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin>>t;
    while (t--){
        solve();
    }
}