#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)

 
void solve(){
    int n,k;
    cin>>n>>k;
    vector<set<int>> adj(n+1);
    vector<int> arr(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        arr[u]++;
        arr[v]++;
    }
    queue<int> q;
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);

    for(int i=1;i<=n;i++) {
        if(arr[i] == 1) q.push(i);
    }

    while(k--){
        queue<int> temp;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            s.erase(node);
            arr[node]--;
            for(int it: adj[node]){
                adj[it].erase(node);
                arr[it]--;
                if(arr[it] == 1) temp.push(it);
            }
        }
        if(temp.empty()) {
            s.clear();
            break;
        }
        q = temp;
    }
    cout<<s.size()<<'\n';




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