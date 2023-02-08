#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include "atcoder/dsu.hpp"
using namespace atcoder;
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
using P = pair<long, char>;
const ll INF = 1ll << 60;
// const ll mod = 10e9+7;


ll n,m;
int main(){
    cin >> n;
    vector<P> p(n);
    //頂点の格納
    rep(i,0,n){
        cin >> p[i].first >> p[i].second;
    }
    map<P, int> mp;  //mapで頂点番号を逆引きできるように
    rep(i,0,n) {mp[p[i]] = i;}
    dsu d(n);
    rep(i,0,n){
        auto [x,y] = p[i]; //構造化束縛 (structured bindings)
        auto check = [&](P q){ //ラムダ式を変数に代入
            if(mp.count(q)){
                d.merge(i,mp[q]);
            }
        };
        check(P(x+1,y));
        check(P(x,y+1));
        check(P(x+1,y+1));
    }
    int ans = 0;
    rep(i,0,n){ 
        if(d.leader(i) == i) ans++;
    }
    cout << ans << endl;
    return 0;

}

