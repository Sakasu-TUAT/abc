#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
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

int main(){
    ll m,n; cin >> n >> m;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    vector<vector<ll>> dp(n+1, vector<ll> (n+1));
    //dp[i][j]:=i番目までにj個の整数を選択したときの計算結果のmax
    dp[0][0] = 0;
    dp[0][1] = -INF;
    rep(i,1,n+1){
        rep(j,0,n+1){
            if(j==0) dp[i][0] = 0;
            else if(j>i) dp[i][j] = -INF;
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + a[i-1]*j);
        }
    }
    cout << dp[n][m] << endl;

}