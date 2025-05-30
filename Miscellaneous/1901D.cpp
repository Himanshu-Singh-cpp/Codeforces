#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> arr1(n+1);
    arr1[0] = 0;
    for(int i=0;i<n;i++){
        arr1[i+1] = max(arr[i],arr1[i]+1);
    }
    vector<int> arr2(n+1);
    arr2[n] = 0;
    for(int i=n-1;i>=0;i--) arr2[i] = max(arr[i],arr2[i+1]+1);

    int ans = 1e15;
    for(int i=0;i<n;i++) {
        int left = arr1[i];
        int right = arr2[i+1];
        int curr = arr[i];
        curr = max(curr,max(left+n-i,right+i+1));
        ans = min(curr,ans);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin>>t;
    while (t--){
        solve();
    }
}