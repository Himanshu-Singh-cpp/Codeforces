#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int a,b;
    cin>>a>>b;
    int target = max(a,b);
    int mini = min(a,b);
    int ans = 1e9;

    for(int i=1;i<=1e5;i++){
        int extra = 0;
        if(target % i != 0) extra = 1;
        if(mini % i != 0) extra++;
        ans = min(ans, mini/i + target/i + (i - 1) + extra);
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