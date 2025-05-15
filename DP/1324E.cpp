#include<bits/stdc++.h>
using namespace std;
 
// #define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    // n -> number of times Vova sleep
    // h -> number of hours in a day
    // l,r -> good sleeping segment

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<pair<int,bool>>> dp(n+1,vector<pair<int,bool>>(h+1,{0,false}));
    // dp[i][j].second -> is reaching jth hour possible at ith index
    // dp[i][j].first -> max possible good sleeping hours till index i waking up at jth hour
    dp[0][0].second = true;

    for(int i=0;i<n;i++){
        for(int j=0;j<=h;j++){
            if(dp[i][j].second){
                int time1 = (j+arr[i]-1)%h;
                int time2 = (j+arr[i])%h;

                if(time1 >= l && time1 <= r) dp[i+1][time1].first = max(dp[i][j].first+1,dp[i+1][time1].first);
                else dp[i+1][time1].first = max(dp[i][j].first,dp[i+1][time1].first);

                if(time2 >= l && time2 <= r) dp[i+1][time2].first = max(dp[i][j].first+1,dp[i+1][time2].first);
                else dp[i+1][time2].first = max(dp[i][j].first,dp[i+1][time2].first);

                dp[i+1][time1].second = true;
                dp[i+1][time2].second = true;
            }
        }
    }


    int ans = 0;
    for(int i=0;i<=h;i++) ans = max(ans,dp[n][i].first);
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