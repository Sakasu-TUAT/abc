#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>
#include <algorithm>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
const ll mod = 998244353;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template <class T, class U> bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U> bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
template <class Head, class... Tail> void in(Head&& head, Tail&&... tail) {cin >> head;in(std::forward<Tail>(tail)...);}
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
vector<bool> Eratostenes(int n){ vector<bool> isprime(n+1, true);isprime[1] = false; rep(p,2,n+1){ if(!isprime[p]) continue; for(int q = p*2; q <= n; q+=p){ isprime[q] = false; }} return isprime;}
ll power(ll a, ll b) { ll ans = 1;for(ll i=0; i<60; i++){if(b & (1LL<<i)) {ans *= a;ans %= mod;}a *= a;a %= mod;}return ans;}
ll combination(ll n, ll k){ assert(!(n < k)); assert(!(n < 0 || k < 0)); ll s = 1, t = 1; rep(i,1,k+1){ s = s*(n-i+1) % mod; t = t*i % mod; } return s * power(t, mod-2) % mod;}

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {-1, 0, 1, 0};

int main(){
    string S; cin >> S;
    int n = S.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1+1));
    dp[0][0] = 1;
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(S[i-1]=='(' or S[i-1] == '?') {
                dp[i][j] += (dp[i-1][j-1])%mod;
                dp[i][j] %= mod;
            }
            if((S[i-1]==')' or S[i-1] == '?')) {
                dp[i][j-1] += (dp[i-1][j])%mod;
                dp[i][j-1] %= mod;
            }
        }
    }
    printTable(dp);
    cout << dp[n][0]%mod << endl;


    return 0;
}