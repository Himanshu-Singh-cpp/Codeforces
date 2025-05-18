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

    vector<int> power(n,0);
    for(int i=0;i<n-1;i++){
        if(arr[i] <= arr[i+1]){
            int cnt = 0;
            int temp = arr[i+1]/2;
            while(arr[i] <= temp){
                cnt++;
                temp /= 2;
            }
            power[i+1] = max(0LL,power[i]-cnt);
        } else {
            int cnt = 0;
            int temp = arr[i+1];
            while(arr[i] > temp){
                temp *= 2;
                cnt++;
            }
            power[i+1] = power[i] + cnt;
        }
    }
    cout<<accumulate(power.begin(),power.end(),0LL)<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin>>t;
    while (t--){
        solve();
    }
}