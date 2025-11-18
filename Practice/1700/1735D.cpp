#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n,k;
    cin>>n>>k;

    map<vector<int>,int> dict;
    vector<vector<int>> arr(n,vector<int>(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
        }
        if(dict.find(arr[i]) == dict.end()){
            dict[arr[i]] = 1;
        } else {
            dict[arr[i]]++;
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(j == i) continue;

            vector<int> req(k);
            for(int l=0;l<k;l++){
                if(arr[i][l] == arr[j][l]) req[l] = arr[i][l];
                else req[l] = 3 - arr[i][l] - arr[j][l];
            }
            if(dict.find(req) != dict.end()) cnt++;
        }
        cnt /= 2;
        ans += (cnt*(cnt-1LL))/2LL;
    }

    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
}