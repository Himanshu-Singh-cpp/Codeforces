#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n,k;
    cin>>n>>k;
    // n -> max value
    // k -> length of the sequence
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    // dp[i][j] -> ending number is i, length of sequnce is j
    // for(int i=1;i<=k;i++) dp[1][i] = 1;
    for(int i=1;i<=n;i++) dp[i][1] = 1; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<k;j++){
            for(int m=i;m<=n;m+=i){
                dp[m][j+1] = (dp[m][j+1] + dp[i][j])%MOD; 
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans = (ans + dp[i][k])%MOD;
    cout<<ans;



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