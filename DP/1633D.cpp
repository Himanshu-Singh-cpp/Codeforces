#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(vector<int>& dp){
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    vector<vector<int>> profit(n+1,vector<int>(k+1,0));
    // dp[i][j] -> maximum profit till ith index by speding j coins

    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            profit[i+1][j] = profit[i][j];
            if(j >= dp[arr[i]]) profit[i+1][j] = max(profit[i+1][j],profit[i][j-dp[arr[i]]] + coins[i]);
        }
    }

    cout<<profit[n][k]<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> dp(1e6+1,INF);
    dp[1] = 0;
    for(int i=1;i<=1e6;i++){
        for(int j=2*i;j<=1e6;j+=i){
            dp[j] = min(dp[j],dp[j-i] + 1);
        }
    }
    int t = 1;
    cin>>t;
    while (t--){
        solve(dp);
    }
}