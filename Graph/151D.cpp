#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

struct DSU {
    vector<int> par;
    int size;

    DSU(int n){
        par.resize(n);
        iota(par.begin(),par.end(),0);
        size = n;
    }

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = this->find(par[x]);
    }

    void unite(int x,int y){
        if(find(x) == find(y)) return;
        par[find(x)] = find(y);
    }

    int find_size(){
        set<int> s;
        for(int i=0;i<size;i++) s.insert(find(i));
        return s.size();
    }

};

int power(int a, int b){
    int ans = 1;
    while(b > 0){
        if((b&1) == 1){
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    DSU dsu(n);

    for(int i=0;i+k-1<n;i++){
        int left = i;
        int right = i+k-1;
        while(left < right){
            dsu.unite(left++,right--);
        }
    }

    cout<<power(m,dsu.find_size());



}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
}