#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n;
    cin>>n;

    vector<int> arr(n+1,0);
    map<int,set<int>> dict;
    for(int i=2;i<=n;i++){
        int ind;
        cin>>ind;
        arr[ind]++;
        if(dict.find(ind) == dict.end()) dict[ind] = {};
        dict[ind].insert(i);
    }
    for(int i=0;i<=n;i++) {
        if(dict.find(i) == dict.end()) continue;
        int cnt = 0;
        for(int it: dict[i]) if(arr[it] == 0) cnt++;
        if(dict[i].size() != 0 && cnt < 3) {
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
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