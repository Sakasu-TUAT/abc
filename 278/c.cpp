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
using P = pair<ll, ll>;
// const ll mod = 10e9+7;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

map<P,bool> mp;

int main(){
    ll n,q; cin>>n>>q;
    rep(i,0,q){
        ll t,a,b; 
        cin >> t >> a >> b;
        if(t==1) {
            mp[P{a,b}] = true;
        }
        if(t==2) {
            mp[P{a,b}] = false;
        }
        if(t==3){
            if(mp[P{a,b}] and mp[P{b,a}]){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
