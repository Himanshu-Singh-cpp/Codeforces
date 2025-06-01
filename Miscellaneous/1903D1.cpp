#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n,q;
    cin>>n>>q;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    while(q--){
        vector<bool> taken(n,false);
        int k;
        cin>>k;
        int ans = 0;
        for(int i=60;i>=0;i--){
            vector<bool> used(n,false);
            int temp = 0;
            bool check = true;
            for(int j=0;j<n;j++){
                if(((((arr[j]>>i)&1) == 0) || (taken[j]))){
                    // cout<<j<<' ';
                    if(taken[j]){
                        temp += 1LL<<i;
                    }
                    else{
                        temp += (1LL<<i) - ((arr[j])&((1LL<<(i+1))-1LL));
                        used[j] = true; 
                    }
                    if(temp > k){
                        check = false;
                        break;
                    }
                }
            }
            // cout<<temp<<' '<<ans<<' '<<i<<'\n';
            // for(int j=0;j<n;j++) cout<<taken[j]<<' '<<used[j]<<' ';
            // cout<<'\n';
            if(check){
                ans += (1LL<<i);
                k -= temp;
                for(int j=0;j<n;j++) taken[j] = (taken[j]|used[j]);
            }

        }
        cout<<ans<<'\n';
    }
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