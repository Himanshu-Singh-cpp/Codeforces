#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

struct DSU{
    vector<int> par;
    int size;

    DSU(int n){
        par.resize(n);
        iota(par.begin(),par.end(),0);
        size = n;
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

    bool same_set(int x, int y){
        return (this->find_par(x) == this->find_par(y));
    }
};

void solve(){
    int n,m1,m2;
    cin>>n>>m1>>m2;

    vector<vector<int>> adj1(n);
    vector<vector<int>> adj2(n);
    
    DSU dsu1 = DSU(n);
    DSU dsu2 = DSU(n);
    
    set<pair<int,int>> egdes;

    for(int i=0;i<m1;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
        egdes.insert({u,v});
        egdes.insert({v,u});
        dsu1.unite(u,v);
    }
    for(int i=0;i<m2;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        egdes.insert({u,v});
        egdes.insert({v,u});
        dsu2.unite(u,v);
    }

    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(egdes.find({i,j}) == egdes.end()){
                if(!dsu1.same_set(i,j) && !dsu2.same_set(i,j)){
                    dsu1.unite(i,j);
                    dsu2.unite(i,j);
                    ans.push_back({i,j});
                }
            } 
        }
    }
    cout<<ans.size()<<'\n';
    for(auto it:ans) cout<<(it.first+1)<<' '<<(it.second+1)<<'\n';

    
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