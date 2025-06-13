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

    int maxi = *max_element(arr.begin(),arr.end());
    vector<int> sieve(maxi+1,1);
    sieve[0] = sieve[1] = 0;
    set<int> primes;
    for(int i=2;i<=maxi;i++) if(sieve[i] == 1) {
        primes.insert(i);
        for(int j=2*i;j<=maxi;j+=i) sieve[j] = 0;
    }


    vector<int> dp(maxi+1,0);
    // dp[j] -> max length of the dp with factor as j till index i
    for(int i=0;i<n;i++){
        vector<int> factors;
        int temp = arr[i];
        for(int j:primes){
            if(j*j > temp) break;
            if(temp % j == 0) {
                factors.push_back(j);
                while(temp % j == 0) temp /= j;
            }
        }
        if(temp > 1) factors.push_back(temp);
        int ans = 1;
        for(int it: factors) ans = max(ans,dp[it]+1);
        for(int it: factors) dp[it] = ans;
    }

    cout<<max(1LL,*max_element(dp.begin(),dp.end()));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    // cin >> t;
    while(t--){
        solve();
    }
}