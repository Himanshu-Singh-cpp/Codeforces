#include<bits/stdc++.h>
using namespace std;
 
// #define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n;
    cin>>n; // n -> number of players

    string s;
    cin>>s; // which player the ith player is attacking 

    vector<int> chunks;
    char prev = s[0];
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(prev == s[i]) {
            cnt++;
        }
        else {
            chunks.push_back(cnt);
            cnt = 1;
            prev = s[i];
        }
    }
    chunks.push_back(cnt);
    if(s[0] == s[n-1]) {
        chunks[0] += chunks[chunks.size()-1];
        if(chunks.size() != 1) chunks.pop_back();
        else {
            chunks[0] /= 2;
            cout<<(chunks[0]+2)/3<<'\n';
            return;
        }
    }
    
    int ans = 0;
    for(int i=0;i<chunks.size();i++) ans += chunks[i]/3;
    cout<<ans<<'\n';
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