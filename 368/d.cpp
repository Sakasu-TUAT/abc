#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>
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
#include <unordered_set>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <algorithm>
#include <cstdlib>
#include <ranges>
#include <numeric>
#include <chrono>
#include <atcoder/all>

#ifdef LOCAL
  #include "settings/debug.cpp"
  #define _GLIBCXX_DEBUG
#else
  #define Debug(...) void(0)
#endif

#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=n;i--;)
#define rrep2(i,n) for(ll i=n;i--;)
#define rrep3(i,a,b) for(ll i=a;i>=b;i--)
#define rrep4(i,a,b,c) for(ll i=(b)+((a)-(b)-1)/(c)*(c);i>=(b);i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)

#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vd = vector<double>;
using vvd = vector<vd>;
using vld = vector<long double>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;

template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
template <class T, class U> bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U> bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
template <class Head, class... Tail> void in(Head&& head, Tail&&... tail) { cin >> head; in(std::forward<Tail>(tail)...); }
template <typename T> istream &operator>>(istream &is, vector<T> &v){for (ll i = 0; i < v.size(); ++i) is >> v[i]; return is;}

const ll INF = 1LL << 60;
const ll mod = 998244353;
using namespace atcoder;
using mint = modint998244353;
using Graph = vector<vector<ll>>;
// struct Edge {ll to;};
struct Edge {ll to; ll cost;};
// using Graph = vector<vector<Edge>>;

vl dijkstra(cauto G, ll start){
    vl cost(G.size(), INF);
    priority_queue<P, vector<P>, greater<P>> pq; //cost, nvがcostで昇順
    pq.emplace(cost[start] = 0, start);
    while(!pq.empty()){
        auto [curCost, cv]  = pq.top(); pq.pop();
        if(curCost > cost[cv]) continue;
        for(cauto [nv, nxCost] : G[cv]){
            if(chmin(cost[nv], cost[cv]+nxCost)){
                pq.emplace(cost[nv], nv);
            }
        }
    }
    return cost;
}

const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

const ll ddx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const ll ddy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
 
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

// 整数値 x にハッシュ値を割り当てる関数
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// int op (int a, int b) {return max(a, b);}
// int e () { return 0; }

using S = long long;
using F = long long;
ll ID = INF;
S op(S a, S b){ return std::max(a, b); } //中身で何を求めるか
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return ID; }


const int MAX = 510000;
mint fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD%i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

// 二項係数計算
mint COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}

int main() {       
    ll n; cin >> n;
    string s; cin >> s;


}

