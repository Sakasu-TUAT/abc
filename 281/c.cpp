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

// map<P,bool> mp;

int main(){
    ll n,t; cin>>n>>t;
    ll cycle = 0;
    vector<ll> sum(n+1);
    sum[0]=0;
    rep(i,0,n){
        ll a;
        cin >> a;
        sum[i+1] = sum[i]+a;
        cycle += a;
    }
    ll shou = t/cycle;
    ll amari = t%cycle;
    cerr << "T: " << cycle << endl;
    cerr << "amari: " << amari << endl;
    for(int i=0; i<n; i++){
        cerr << "sum[i] = " << sum[i+1] << endl;
        if(amari<=sum[i+1]){
            cout << i+1 << " " << amari-sum[i] << endl;
            return 0;
        }
    }

    return 0;
}
