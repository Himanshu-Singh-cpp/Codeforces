#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n;
    cin>>n;
    vector<string> mat(n);
    for(int i=0;i<n;i++){
        cin>>mat[i];
    }
    vector<vector<int>> add(n,vector<int>(n+1,0));
    vector<vector<int>> sub(n,vector<int>(n+1,0));
    int ans = 0;
    for(int i=0;i<n;i++){
        vector<int> curr(n,0);
        for(int j=0;j<n;j++) {
            curr[j] = (add[i][j] + sub[i][j] + curr[max(0,j-1)])%2;
        }
        for(int j=0;j<n;j++){
            int val = (curr[j] + mat[i][j])%2;
            if(val == 1){
                ans++;
                add[i][j]++;
                sub[i][j+1]++;
            } 
        }
        if(i < n-1){
            for(int j=0;j<n;j++){
                add[i+1][max(0,j-1)] += add[i][j];
                sub[i+1][min(n,j+1)] += sub[i][j];
            }
        }
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