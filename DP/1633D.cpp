#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(vector<int>& dp){
    int n,k;
    cin>>n>>k;

    k = min(k,12*n);

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    // vector<vector<int>> profit(n+1,vector<int>(k+1,0));
    // dp[i][j] -> maximum profit till ith index by speding j coins
    vector<int> curr(k+1,0);
    vector<int> next(k+1); 

    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            // profit[i+1][j] = profit[i][j];
            next[j] = curr[j];
            // if(j >= dp[arr[i]]) profit[i+1][j] = max(profit[i+1][j],profit[i][j-dp[arr[i]]] + coins[i]);
            if(j >= dp[arr[i]]) next[j] = max(next[j], curr[j-dp[arr[i]]] + coins[i]);
        }
        curr = next;
    }

    cout<<curr[k]<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> dp(1e3+1,INF);
    dp[1] = 0;
    for(int i=2;i<=1e3;i++){
        for(int j=1;j<i;j++){
            if((i-j)<= j && j/(j/(i-j)) == i-j) dp[i] = min(dp[i],dp[j]+1);
        }
    }
    int t = 1;
    cin>>t;
    while (t--){
        solve(dp);
    }
}