#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    string t; // t -> length max 100 
    cin>>t;

    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int len = t.length();
    vector<int> dp(len+1,INF);
    dp[0] = 0;
    vector<pair<int,int>> back_track(len+1,{0,0});
    for(int i=0;i<len;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<arr[j].length();k++){
                if(i+k>=len || arr[j][k] != t[i+k]) break;
                if(k == arr[j].length() - 1) for(int l=0;l<=k;l++) if(dp[i+l+1]>dp[i]+1){
                    dp[i+l+1] = dp[i]+1;
                    back_track[i+l+1].first = i;
                    back_track[i+l+1].second = j;
                }
            }
        }
    }

    // for(int i=0;i<=len;i++) cout<<back_track[i].first<<' '<<back_track[i].second<<'\n';

    if(dp[len] == INF) cout<<"-1\n";
    else {
        cout<<dp[len]<<'\n';
        int curr = len;
        while(curr > 0){
            cout<<back_track[curr].second+1<<' '<<back_track[curr].first+1<<'\n';
            curr = back_track[curr].first;
        }
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    cin>>t;
    while (t--){
        solve();
    }
}