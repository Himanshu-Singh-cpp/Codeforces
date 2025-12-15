#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (long long)(998244353)

int pow(int a,int b){
    int val = 1;
    while(b > 0){
        if((b&1) == 1) val *= a, val %= MOD;
        b >>= 1;
        a = (a*a)%MOD;
    }
    return val;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int suma = accumulate(arr.begin(),arr.end(),0LL);
    int curr = 0;
    int val = suma;
    int ans = pow(2,n);
    int prev_mini = 0;
    int prev_maxi = 0;
    int prev_ways_mini = 0;
    int prev_ways_maxi = 1;
    for(int i=0;i<n;i++){
        int numa = prev_mini + arr[i];
        int numb = abs(prev_mini + arr[i]);
        int numc = prev_maxi + arr[i];
        int numd = abs(prev_maxi + arr[i]);
        int mini = min(numa,numc);
        int maxi = max(numb,numd);
        int ways_mini = 0;
        int ways_maxi = 0;
        if(maxi != mini){
            if(numa == mini) ways_mini += prev_ways_mini;
            if(numb == mini) ways_mini += prev_ways_mini;
            if(numc == mini) ways_mini += prev_ways_maxi;
            if(numd == mini) ways_mini += prev_ways_maxi;
            if(numa == maxi) ways_maxi += prev_ways_mini;
            if(numb == maxi) ways_maxi += prev_ways_mini;
            if(numc == maxi) ways_maxi += prev_ways_maxi;
            if(numd == maxi) ways_maxi += prev_ways_maxi;
        } else {
            ways_maxi += 2*prev_ways_maxi + 2*prev_ways_mini;
        }
        prev_mini = mini;
        prev_maxi = maxi;

        prev_ways_maxi = ways_maxi%MOD;
        prev_ways_mini = ways_mini%MOD;
        // cout<<mini<<' '<<ways_mini<<' '<<maxi<<' '<<ways_maxi<<'\n';
    }
    cout<<prev_ways_maxi<<'\n';



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