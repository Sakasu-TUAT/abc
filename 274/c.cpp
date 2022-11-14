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
    vector<int> a(n+2);
    // vector<int>tree(pow(2,n)+1);
    // tree[1] = 1;
    rep(i,1,n+1){
        cin>>a[i];
    }
    map<int,int> mp;
    rep(i,1,n+1){
        // tree[2*a[i]]   = 2*i;
        mp[2*i] = 2*a[i];
        // tree[2*a[i]+1] = 2*i+1;
        mp[2*i+1] = (2*a[i]+1);
    }
    // for(auto &v : tree){
    //     cerr << v << ", ";
    // }
    // cerr << endl;
    rep(i,1,2*n+2){
        int ans = 0;
        while(1){
            mp[i] /= 2;
            ans++;
            if(mp[i]==0) break;
        }
        ans--; 
        cout << ans << endl;
    }
    
    return 0;
}