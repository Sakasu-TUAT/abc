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
using namespace atcoder;


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
// const ll mod = 100000000;
using mint = modint998244353;
// using Graph = vector<vector<ll>>;
// struct Edge {ll to;};
// struct Edge {ll to; ll cost;};
// using Graph = vector<vector<Edge>>;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, +1, 0, -1};
 

struct edge {
    ll u, v, w;
    edge(ll a, ll b, ll c) : u(a), v(b), w(c) {}
    edge() : u(0), v(0), w(0) {}
    bool operator<(const edge& other) const {
        return w < other.w;
    }
};
 
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


int main() {
    ll n, q; in(n, q);
    vector<edge> G(n);
    rep(i,0,n-1){
        ll a, b, c; in(a, b, c); a--; b--;
        edge e = edge(a, b, c);
        G[i] = e;
    }
    dsu d(n);
    ll sum = 0;
    sort(all(G));
    for(cauto e : G){
        if(d.same(e.u, e.v)) continue;
        d.merge(e.u, e.v);
        sum += e.w;
    }
    vector<edge> queries(q);
    rep(i,0,q){
        ll u, v, w; cin >> u >> v >> w; u--; v--;
        edge e = edge(u, v, w);
        queries[i] = e;
        if(!d.same(u, v)){
            d.merge(u, v);
            sum += w;
        } 
    }
    cerr << sum << endl;
    vl ans;
    ans.emplace_back(sum);
    reverse(all(queries));
    rep(i,1,q){
        edge e = queries[i];
        if(d.same(e.u, e.v)){
            ans.emplace_back(ans.back() - G.back().w + e.w);
        } else {
            d.merge(e.u, e.v);
            ans.emplace_back(ans.back() + e.w);
        }
    }
    reverse(all(ans));
    for(cauto v : ans){
        cout << v << endl;
    }




}