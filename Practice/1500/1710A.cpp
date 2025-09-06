#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> arr(k);
    for(int i=0;i<k;i++) cin>>arr[i];

    int curr = n*m;
    bool greater = false;
    for(int i=0;i<k;i++){
        if(arr[i] >= 2*n) curr -= (arr[i] - arr[i]%n);
        if(arr[i] >= 3*n) greater = true;
    }
    if(curr <= 0){
        if(m%2 == 0 || greater){
            cout<<"Yes\n";
            return;
        }
    }
    greater = false;
    curr = n*m;
    for(int i=0;i<k;i++){
        if(arr[i] >= 2*m) curr -= (arr[i] - arr[i]%m);
        if(arr[i] >= 3*m) greater = true;
    }
    if(curr <= 0 && (n%2 == 0 || greater)){
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";

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