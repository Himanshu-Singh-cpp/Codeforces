#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int ind = i;ind<n;ind+=i+1){
            if(arr[ind] > arr[i]) dp[ind] = max(dp[i]+1,dp[ind]);
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<'\n';
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