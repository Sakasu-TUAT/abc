#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
using namespace std;
// #define rep(i,n) for(ll i=0; i<(n); ++i)
#define Out(x) cout << x << endl
#define Yes "Yes"
#define No "No"
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
using ll = long long;
using P = pair<vector<ll>, bool>;
// const ll mod = 10e9+7;

int main(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    map<int,bool> mp;
    map<int,int> ans;
    rep(i,0,n){
        cin >> a[i];
        if(mp[a[i]]==false){
            mp[a[i]]=true;
            b[i] = a[i];
        }
    }
    sort(b.begin(), b.end());
    for(auto &v : b){
        cerr << v << ",";
    }
    cout << endl;
    int idx_lower;
    rep(i,0,n){
        auto pos = lower_bound(b.begin(), b.end(), a[i]);  //二分探索
        idx_lower = distance(b.begin(), pos) + 1;
        // cerr << "idx= " << idx_lower << endl;
        int kindNum = n-idx_lower;
        // cerr << i << " == " << kindNum << endl;
        ans[kindNum]++;
    }
    rep(i,0,n){
        cout << ans[i] << endl;
    }
    return 0;
}