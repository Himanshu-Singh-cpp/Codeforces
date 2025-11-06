#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans = 0;
    
    int curr = 0;
    vector<int> modified;
    while(curr < n){
        if(arr[curr] == 1 || arr[curr] == 2){
            bool two = false;
            while((curr < n) && (arr[curr] == 1 || arr[curr] == 2)){
                if(arr[curr] == 2) two = true;
                curr++;
            }
            if(two) modified.push_back(2);
            else modified.push_back(1);
        } else {
            modified.push_back(0);
            curr++;
        }
    }

    int sz = modified.size();
    // for(int i=0;i<sz;i++){
    //     cout<<modified[i]<<' ';
    // }
    // cout<<'\n';
    vector<int> red(sz,0);
    for(int i=0;i<sz;i++){
        if(modified[i] == 2){
            ans++;
            red[i] = 1;
            red[max(0,i-1)] = 1;
            red[min(i+1,sz-1)] = 1;
        } else if(modified[i] == 1){
            ans++;
            red[i] = 1;
            if(i > 0 && red[i-1] == 0){
                red[i-1] = 1;
            } else if(i < sz-1 && red[i+1] == 0){
                red[i+1] = 1;
            }
        }
    }
    cout<<ans+ count(red.begin(),red.end(),0)<<'\n';
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