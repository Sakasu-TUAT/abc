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
using P = pair<int, int>;
// const ll mod = 10e9+7;


int main(){
	ll n; cin>>n;
    vector<ll> a;
    for(ll i=n;; i=(i-1)&n){
        a.emplace_back(i);
        if(i==0) break;
    }
    reverse(a.begin(), a.end());
    for(auto &v: a){
        cout << v << endl;
    }
    return 0;
}