#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
#include <unordered_map>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define Out(x) cout << x << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
using ll = long long;
using P = pair<string, string>;
// const ll mod = 10e9+7;

int main(){
    int n; cin>>n;
    vector<string> s(n),t(n);
    unordered_map<string, int> mp;
    rep(i,0,n){
        cin>>s[i]>>t[i];
        if(!mp.count(s[i])) mp[s[i]] = mp.size();
        if(!mp.count(t[i])) mp[t[i]] = mp.size();
    }
    int m = mp.size();
    dsu d(m);
    rep(i,0,n){
        int u = mp[s[i]];
        int v = mp[t[i]];
        if(d.same(u,v)){
            No;
            return 0;
        }
        d.merge(u,v);
    }
    Yes;
    return 0;

}
