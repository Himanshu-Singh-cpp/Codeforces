#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    int n,m;
    cin>>n>>m;
    bool swapped = false;
    if(n < m) swap(n,m), swapped = true;
    vector<vector<int>> ans(n,vector<int>(m));
    int row = 0;
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<=m;j++){
            ans[row][j-1] = (i-1)*m+j;
        }
        row++;
    }
    
    for(int i=2;i<=n;i+=2){
        for(int j=1;j<=m;j++){
            ans[row][j-1] = (i-1)*m+j;
        }
        row++;
    }
    if(swapped){
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                cout<<ans[i][j]<<' ';
            }
            cout<<'\n';
        }
    } else {
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    cout<<'\n';
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