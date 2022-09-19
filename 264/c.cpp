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
	ll m,n; cin >> n >> m;
    vector<ll> a(n),  baseSum(n+1);
    ll now = 0;
    rep(i,0,n) cin >> a[i];
    rep(i,0,m){
        now += a[i]*(i+1);
        // cerr << currentMax << endl;
    } 
    rep(i,0,n){
        baseSum[i+1] = baseSum[i] + a[i]; 
        cerr << baseSum[i+1] << endl;
    }
    ll ans = now;
    rep(i,m,n){
        ll b = now - (baseSum[i]-baseSum[i-m]) + a[i]*m;
        cerr << now << "-("<< baseSum[i] - (baseSum[i-m]) << ") + " <<"(" << a[i] << ")*(" << m  << ") = " << b << endl;  
        ans = max(ans, b);
        // cerr << now << "-("<< baseSum << ")+(" << a[i] << ")*(" << m  << ") = " << b << endl; 
        // cerr << "a[i-m]: " << a[i-m] << " a[i]: " << a[i] << endl; 
        // baseSum = baseSum - a[i-m] + a[i];
        now = b;
    }

    cout << ans << endl;
}