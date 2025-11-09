#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    if(accumulate(arr.begin(),arr.end(),0LL)%n != 0){
        cout<<"no\n";
        return;
    }
    int val = accumulate(arr.begin(),arr.end(),0LL)/n;
    map<int,int> dict;
    for(int i=0;i<n;i++){
        int diff = abs(arr[i] - val);
        if(diff != 0){
            bool found_one = false;
            bool end = false;
            int first_set = -1;
            for(int j=0;j<32;j++){
                if((diff>>j)&1){
                    found_one = true;
                    if(first_set == -1) first_set = j;
                }
                if(found_one && (((diff>>j)&1) == 0)){
                    end = true;
                }
                if(end && (((diff>>j)&1) == 1)){
                    cout<<"NO\n";
                    return;
                }
            }

            int smaller = 1<<first_set;
            int larger = smaller + diff;
            if(dict.find(smaller) == dict.end()) dict[smaller] = 0;
            if(dict.find(larger) == dict.end()) dict[larger] = 0;
            if(arr[i] - val > 0){
                dict[larger]++;
                dict[smaller]--;
            } else {
                dict[larger]--;
                dict[smaller]++;
            }
        }
        
    }
    for(auto it:dict){
        if(it.second != 0){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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