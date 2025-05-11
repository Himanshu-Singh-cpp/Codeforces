#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(vector<int>& dp){
    int n,m;
    cin>>n>>m;
    // n -> initial number
    // m -> number of operations
    int ans = 0;
    while(n > 0){
        ans = (ans + dp[n%10+m])%MOD;
        n /= 10;
    }
    cout<<ans<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // precaculate based on m
    vector<int> dp(2e5+10,0);
    dp[0] = 1;
    vector<int> curr(10,0);
    curr[0] = 1;

    for(int i=1;i<=2e5+9;i++){
        int nines = curr[9];
        for(int j=8;j>=0;j--) curr[j+1] = curr[j];
        curr[0] = nines;
        curr[1] += nines;
        curr[1] %= MOD;
        dp[i] = (dp[i-1] + nines)%MOD;
    }
 
    int t = 1;
    cin>>t;
    while (t--){
        solve(dp);
    }
}