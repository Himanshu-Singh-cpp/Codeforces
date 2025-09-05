#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node, vector<vector<vector<int>>>& adj,int par,vector<int>& answer,int total_cost,vector<int>& st){
    int low = 0;
    int high = st.size() - 1;
    int ans = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(st[mid] <= total_cost){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    answer[node] = ans; 
    for(auto it: adj[node]){
        int neighbour = it[0];
        st.push_back(st[st.size()-1]+it[2]);
        if(neighbour != par) {
            dfs(neighbour,adj,node,answer,total_cost + it[1],st);
        }
        st.pop_back();
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<vector<int>>> adj(n+1);
    
    for(int i=2;i<=n;i++){
        int p,a,b;
        cin>>p>>a>>b;
        adj[i].push_back({p,a,b});
        adj[p].push_back({i,a,b});
    }

    vector<int> answer(n+1,0);

    vector<int> st = {0};
    dfs(1,adj,-1,answer,0,st);

    for(int i=2;i<=n;i++){
        cout<<answer[i]<<' ';
    }
    cout<<'\n';

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