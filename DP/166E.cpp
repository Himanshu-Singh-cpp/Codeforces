#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> dp(2,vector<int>(4,0));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        dp[1][0] = dp[0][1] + dp[0][2] + dp[0][3];
        dp[1][0] %= MOD;
        dp[1][1] = dp[0][0] + dp[0][2] + dp[0][3];
        dp[1][1] %= MOD;
        dp[1][2] = dp[0][0] + dp[0][1] + dp[0][3];
        dp[1][2] %= MOD;
        dp[1][3] = dp[0][0] + dp[0][1] + dp[0][2];
        dp[1][3] %= MOD;
        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[0][2] = dp[1][2];
        dp[0][3] = dp[1][3];
    }
    cout<<dp[1][0];

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