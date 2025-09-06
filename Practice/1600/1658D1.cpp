#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    int l,r;
    cin>>l>>r;
    vector<int> arr(r-l+1);
    for(int i=0;i<r-l+1;i++) cin>>arr[i];

    vector<int> digit(32,0);
    int n = r -l + 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<20;j++){
            digit[j] += (arr[i]>>j)&1;
        }
    }

    int ans = 0;
    for(int i=l;i<=r;i++){
        for(int j=0;j<20;j++){
            digit[j] -= (i>>j)&1;
        }
    }
    for(int i=0;i<20;i++)
    if(digit[i] != 0){
        ans ^= (1<<i);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    cin >> t;
    while(t--){
        solve();
    }
}