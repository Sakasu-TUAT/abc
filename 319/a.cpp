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
#include <cinttypes>
#include <algorithm>
#include <cstdlib>
#include <atcoder/all>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<ll, ll>;
using vll = vector<ll>;
using vi = vector<int>;
using vd = vector<double>;
using vld = vector<long double>;
using vll2 = vector<vll>;
using vll3 = vector<vll2>;
using vld2 = vector<vld>;
using vld3 = vector<vld2>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<char>;
using vb = vector<bool>;
using vvb = vector<vb>;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}
const ll INF = 1LL << 60;
const ll mod = 1000000007;
// const ll mod = 998244353;
using Graph = vector<vector<ll>>;
using namespace atcoder;
using mint = modint998244353;

/* encode: ランレングス圧縮を行う
*/
vector<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
/* decode: ランレングス圧縮の復元を行う
*/
string decode(const vector<pair<char, int>>& code) {
    string ret = "";
    for (auto p : code) {
        for (int i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}



// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, 1, -1, 0};

int main() {
    ll n; cin >> n;
    
    vll2 G(n, vll(n));
    rep(i,0,n){
        rep(j,i+1,n){
            cin >> G[i][j];
            G[j][i] = G[i][j];   
        }
    }
    vll dp(1LL<<n);
    rep(i,0,(1LL<<n)){
        rep(j,0,n){
            if(i & (1LL << j)) continue; // 探索済み
            rep(k,j+1,n){
                if(i & (1LL<<k)) continue;
                ll t = i | (1LL << j) | (1LL << k);
                chmax(dp[t], dp[i]+G[j][k]);
            }
        }
    }
    cout << dp[(1LL<<n)-1] << endl;

    return 0;

}


