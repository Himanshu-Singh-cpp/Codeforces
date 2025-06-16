#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    string start;
    string end;
    int k;
    cin>>start>>end>>k;
    int n = start.length();
    
    vector<int> curr(n+1,0);
    // curr[i] -> number of words starting at index i
    curr[0] = 1;
    for(int j=0;j<k;j++){
        vector<int> next(n+1,0);
        int val = 0;
        for(int i=0;i<n;i++) val = (val + curr[i])%MOD;
        for(int i=0;i<n;i++){
            next[i] = (val - curr[i] + MOD)%MOD;
        }
        curr = next; 
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        bool check = true;
        for(int j=0;j<n;j++){
            if(start[(i+j)%n] != end[j]){
                check = false;
                break;
            }
        }
        if(check) ans = (ans + curr[i])%MOD;
    }
    cout<<ans;
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