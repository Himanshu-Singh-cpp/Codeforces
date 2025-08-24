#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};

void solve(){
    int n;
    cin>>n;

    set<pair<int,int>> nodes;
    vector<pair<int,int>> nodes_vec;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        nodes.insert({x,y});
        nodes_vec.push_back({x,y});
    }
    map<pair<int,int>,pair<int,int>> dict;
    queue<vector<int>> qu;

    // nodes with available on dist 1
    for(auto it:nodes){
        for(int i=0;i<4;i++){
            int xdx = it.first + dx[i];
            int ydy = it.second + dy[i];
            if(nodes.find({xdx,ydy}) == nodes.end()){
                dict[{it.first,it.second}] = {xdx,ydy};
                qu.push({it.first,it.second,xdx,ydy});
                break;
            }
        }
    }
    // run bfs to find answers for other nodes
    while(!qu.empty()){
        int x = qu.front()[0];
        int y = qu.front()[1];
        int ans_x = qu.front()[2];
        int ans_y = qu.front()[3];
        qu.pop();
        for(int i=0;i<4;i++){
            int xdx = x + dx[i];
            int ydy = y + dy[i]; 
            if((nodes.find({xdx,ydy}) != nodes.end()) && (dict.find({xdx,ydy}) == dict.end())){
                qu.push({xdx,ydy,ans_x,ans_y});
                dict[{xdx,ydy}] = {ans_x,ans_y};
            }
        }
    }
    for(auto it:nodes_vec){
        cout<<dict[it].first<<' '<<dict[it].second<<'\n';
    } 
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    // cin >> t;
    while(t--){
        solve();
    }
}