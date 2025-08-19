#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

struct DSU{
    vector<int> par;

    DSU(int n){
        par.resize(n);
        iota(par.begin(),par.end(),0);
    }

    int find_par(int x){
        if(x == par[x]) return x;
        return par[x] = find_par(par[x]);
    }

    void unite(int x, int y){
        x = find_par(x);
        y = find_par(y);
        if(x == y) return;
        par[x] = y;
    }

};

void solve(){
    int n;
    cin>>n;
    DSU dsu = DSU(n);
    vector<pair<int,int>> remove;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        if(dsu.find_par(u) == dsu.find_par(v)) remove.push_back({u,v});
        dsu.unite(u,v);
    }
    set<int> nodes; 
    for(int i=0;i<n;i++){
        nodes.insert(dsu.find_par(i));
    }
    cout<<(nodes.size()-1)<<'\n';
    vector<int> nodes_vec(nodes.begin(),nodes.end());
    for(int i=0;i<nodes.size()-1;i++){
        cout<<(remove[i].first+1)<<' '<<(remove[i].second+1)<<' '<<(nodes_vec[i]+1)<<' '<<(nodes_vec[i+1]+1)<<'\n';
    }

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