#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

bool possible(vector<vector<int>>& arr, int n,int m,int l){
    vector<vector<int>> pref(n+1,vector<int>(m+1,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val = 0;
            if(arr[i][j] >= l) val = 1;
            pref[i+1][j+1] = val + pref[i+1][j] + pref[i][j+1] - pref[i][j];
            if(i+1 >= l && j+1 >= l){
                if(pref[i+1][j+1] - pref[i+1-l][j+1] - pref[i+1][j+1-l] + pref[i+1-l][j+1-l] >= l*l){
                    return true;
                }
            }
        }
    }
    // cout<<l<<"\n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<pref[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';

    return false;

}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int low = 1;
    int high = min(n,m);
    int ans = 1;
    while(low <= high){
        // cout<<low<<' '<<high<<'\n';
        int mid = low + (high - low)/2;
        if(possible(arr,n,m,mid)){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
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