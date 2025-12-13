#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n;
    cin>>n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<n;i++) cin>>arr2[i];

    vector<int> sorted1(arr1);
    vector<int> sorted2(arr2);

    sort(sorted1.begin(),sorted1.end());
    sort(sorted2.begin(),sorted2.end());

    for(int i=0;i<n;i++) if(sorted1[i] != sorted2[i]) {
        cout<<"NO\n";
        return;
    }

    map<int,int> val_to_idx;
    for(int i=0;i<n;i++) val_to_idx[arr2[i]] = i;

    int val = 0;
    for(int i=0;i<n;i++){
        if(arr1[i] != arr2[i]){
            int idx = val_to_idx[arr1[i]];
            val += 2*(idx-i+1) - 1;
            val %= 2;
            swap(arr2[i],arr2[idx]);
            val_to_idx[arr2[i]] = i;
            val_to_idx[arr2[idx]] = idx;
        }
    }
    if(val%2) cout<<"NO\n";
    else cout<<"YES\n";
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