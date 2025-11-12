#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    if(((n + m)%2 == k%2) && k >= (n+m-2)){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
        return;
    }
    int val = 0;
    if((n+m-2)%4 != k%4) val = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(i == n-1 && (n+j+val)%2 == 1) cout<<"R ";
            else cout<<"B ";
        }
        cout<<'\n';
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(i == 0 && j == 0) cout<<"R ";
            else if(j == 0 && (i + val)%2) cout<<"B ";
            else cout<<"R ";
        }
        cout<<'\n';
    }

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