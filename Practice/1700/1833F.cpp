#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

int power(int a, int b){
    int ans = 1;
    while(b > 0){
        if((b&1) == 1){
            ans = (ans*a)%MOD;
        }
        b >>= 1;
        a = (a*a)%MOD;
    }
    return ans;
}

int inverse(int num){
    return power(num,MOD-2);
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    map<int,int> freq;
    for(int i=0;i<n;i++){
        if(freq.find(arr[i]) == freq.end()) freq[arr[i]] = 1;
        else freq[arr[i]]++;
    }

    if(m == 1) {
        cout<<n<<'\n';
        return;
    }
    int ans = 0;
    int prev = -1;
    int cnt = 0;
    int window_val = 1;
    for(auto it:freq){
        if(it.first == prev + 1){
            if(cnt < m){
                window_val = (window_val*it.second)%MOD;
                cnt++;
            } else {
                window_val = (window_val*it.second)%MOD;
                window_val = (inverse(freq[it.first-m])*window_val)%MOD;
            }
            if(cnt == m){
                ans = (ans + window_val)%MOD;
            }
        } else {
            cnt = 1;
            window_val = it.second;
        }
        prev = it.first;
    }
    cout<<ans<<'\n';
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