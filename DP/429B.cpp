#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>mat[i][j];

    vector<vector<int>> dp1(n+1,vector<int>(m+1,0));
    vector<vector<int>> dp2(n+1,vector<int>(m+1,0));
    vector<vector<int>> dp3(n+1,vector<int>(m+1,0));
    vector<vector<int>> dp4(n+1,vector<int>(m+1,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            int up = (i > 0) ? dp1[i-1][j] : 0;
            int left = (j > 0) ? dp1[i][j-1] : 0;
            dp1[i][j] = max(up,left) + mat[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--) {
            int up = (i > 0) ? dp2[i-1][j] : 0;
            int right = (j < m-1) ? dp2[i][j+1] : 0;
            dp2[i][j] = max(up,right) + mat[i][j];
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--) {
            int down = (i < n-1) ? dp3[i+1][j] : 0;
            int right = (j < m-1) ? dp3[i][j+1] : 0;
            dp3[i][j] = max(down,right) + mat[i][j];
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++) {
            int down = (i < n-1) ? dp4[i+1][j] : 0;
            int left = (j > 0) ? dp4[i][j-1] : 0;
            dp4[i][j] = max(down,left) + mat[i][j];
        }
    }
    int ans = 0;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            int up_down = dp1[i-1][j] + dp3[i+1][j] + dp2[i][j+1] + dp4[i][j-1];
            int left_right = dp1[i][j-1] + dp3[i][j+1] + dp2[i-1][j] + dp4[i+1][j];
            ans = max(ans,up_down);
            ans = max(ans,left_right);
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