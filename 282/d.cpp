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
#include <algorithm>
#include <functional>
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

ll n;
ll k;
ll ans;
ll a[100000000];

ll rec(ll n){
    if(n==k) return 1;
    if(memo[n]!=0) return memo[n];
    ans += a[rec(n+1)];
    if(ans%d==0) memo[n] = 
    return ans;
}

int main(){
    ll d; cin>>n>>k>>d;
    rep(i,0,n){cin>>a[i];}
    ll ans = -1;
    ll i = rec(0);
    cout << i << endl;
   

    return 0;
}