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
const ll INF = 1LL << 60;
// const ll mod = 1000000007;
const ll mod = 998244353;
using namespace atcoder;
// using mint = modint1000000007;
using mint = modint998244353;
// using Graph = vector<vector<ll>>;
// struct Edge {ll to; ll cost;};
using Graph = vector<vector<ll>>;

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

int main() {
    ll n, m; cin >> n >> m;
    vl a(m), b(m);
    rep(i,0,m) cin >> a[i];        
    rep(i,0,m) cin >> b[i]; 
    Graph G(n);
    rep(i,0,m){
        G[--a[i]].emplace_back(--b[i]);
        G[b[i]].emplace_back(a[i]);
    }
    bool ok = true;
    vl x(n, -1);
    auto dfs = [&](auto dfs, int v, int num) -> void {
        x[v] = num;
        for(cauto nv : G[v]){
            if(x[nv]==-1) {
                dfs(dfs, nv, 1^num);
            } else if(x[nv] == x[v]){
                // cerr << "nv: " << nv << ", v: " << v << endl; 
                ok = false;
                return;
            }
        }
    };
    rep(i,0,n){
        if(x[i] != -1) continue;
        dfs(dfs, i, 0);
    }
    // rep(i,0,n){
    //     cerr << x[i] << ", ";
    // }
    cout << ( ok ? "Yes" : "No" ) << endl;


    
}
