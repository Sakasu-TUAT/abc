#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<b; i++)

int main(){
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    vector<pair<int, int>> ans(n);
    rep(i,0,3*n){
        int a; cin >> a;
        mp[a]++;
        if(mp[a]==2){
            ans.push_back({i+1, a});
        }
    }
    sort(ans.begin(), ans.end());
    for(const auto [idx, v] : ans){
        if(v==0) continue;
        cout << v << " ";
    }
    cout << endl;
   
    return 0;
}