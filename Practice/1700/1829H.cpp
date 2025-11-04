#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

int power(int a, int b){ // a**b
    int ans = 1;
    while(b > 0){
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    // sort(arr.begin(),arr.end());

    vector<int> dp(64,0);

    // fill the dp table
    for(int i=0;i<n;i++){
        for(int j=0;j<64;j++){
            dp[j&arr[i]] += dp[j];
            dp[j&arr[i]] %= MOD;
        }
        dp[arr[i]]++;
        dp[arr[i]] %= MOD;
        
    }
    // cout<<arr[1]<<' ';
    // cout<<dp[1]<<' ';
    
    int ans = 0;
    for(int i=0;i<64;i++){
        int cnt = 0;
        for(int j=0;j<=6;j++) if((i>>j)&1) cnt++;
        if(cnt == k) ans = (ans + dp[i])%MOD;
    }

    cout<<ans<<'\n';

    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
}