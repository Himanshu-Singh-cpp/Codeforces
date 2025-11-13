#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++) cin>>arr[i];
    int ind = find(arr.begin(),arr.end(),1) - arr.begin();
    swap(arr[ind],arr[1]);
    int l = 1;
    int r = n+1;
    int last_mid = -1;
    while(r-l != 1){
        int mid = (r+l)/2;
        last_mid = mid;
        if(arr[mid] <= x) l = mid;
        else r = mid;
    }
    cout<<"2 \n";
    cout<<ind<<' '<<"1\n";
    cout<<l<<' '<<find(arr.begin(),arr.end(),x) - arr.begin()<<'\n';
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