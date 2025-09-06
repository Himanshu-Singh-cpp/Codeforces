#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)


void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    if(n % 2 == 0){
        cout<<"2\n";
        cout<<1<<' '<<n<<'\n';
        cout<<1<<' '<<n<<'\n';
    } else {
        cout<<"4\n";
        cout<<1<<' '<<n<<'\n';
        cout<<1<<' '<<n-1<<'\n';
        cout<<n-1<<' '<<n<<'\n';
        cout<<n-1<<' '<<n<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    cin >> t;
    while(t--){
        solve();
    }
}