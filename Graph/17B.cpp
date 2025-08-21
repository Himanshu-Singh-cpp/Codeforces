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

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        par[x] = y;
    }
};

void solve(){
    int n;
    cin>>n;

    vector<int> qual(n);
    for(int i=0;i<n;i++) cin>>qual[i];

    int m;
    cin>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        edges.push_back({a,b,c});
    }
    sort(edges.begin(),edges.end(),[&](const vector<int>& a,const vector<int>& b){
        return a[2] < b[2];
    });

    int ans = 0;
    set<int> st;
    DSU dsu = DSU(n);
    for(auto& it:edges){
        if(dsu.find(it[0]) == dsu.find(it[1]) || (st.find(it[1]) != st.end())) continue;
        dsu.unite(it[0],it[1]);
        ans += it[2];
        st.insert(it[1]);
    }

    set<int> comp;
    for(int i=0;i<n;i++) comp.insert(dsu.find(i));
    if(comp.size() != 1){
        cout<<"-1\n";
        return;
    }
    cout<<ans;


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