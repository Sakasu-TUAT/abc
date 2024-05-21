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
#include <ranges>
#include <numeric>
#include <list>
#include <cctype>
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
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vld = vector<long double>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
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
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
        is >> v[i];
    return is;
}


const ll INF = 1LL << 60;
// const ll mod = 1000000007;
const ll mod = 998244353;
// using mint = modint998244353;
// using Graph = vector<vector<ll>>;
// struct Edge {ll to;};
struct Edge {ll to; ll cost;};
using Graph = vector<vector<Edge>>;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, +1, 0, -1};
 
 
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
};

vector<P> prime_factorize(long long N) {
    vector<P> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

map<int64_t, int> prime_factor(int64_t n) {
    map<int64_t, int> ret;
    for(int64_t i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}


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
using namespace atcoder;

int main(){
    ll n, m; cin >> n >> m;
    Graph G(n);
    dsu d(n);
    rep(i,0,m){
        ll a, b; cin >> a >> b;
        G[--a].emplace_back(--b);
        G[b].emplace_back(a);
        d.merge(a, b);
    }
    ll ans = 0;
    map<ll, ll> mp;
    rep(i,0,n){
        // int r = d.leader(i);
        // mp[r]++;
        if(d.leader(i))
    }
    for(cauto [k, v] : mp){
        // if(v > 1){
        //     ans += v*(v-1)/2;
        // }
    }
    cout << ans << endl;
    
    
}