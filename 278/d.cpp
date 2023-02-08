#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
#include <unordered_map>
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

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

unordered_map<ll, ll> memo;

int main(){
    ll n;
    vector<ll> a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    vector<ll> a1(n, 1);
    ll q;
    vector<pair<ll, ll>> order;
    ll allSum =0;
    map<ll, ll> mp;

    while(q--){
        ll i=0;
        int x; cin>>x;
        if(x==1){
            ll j; cin >> j;
            allSum += j;
        }
        if(x==2){
            ll i, j;
            order.emplace_back(P{i,j});
        }
        if(x==3){

        }
    }
    return 0;
}