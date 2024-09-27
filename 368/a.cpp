#ifdef LOCAL
#include "../settings/pch.hpp" 
#define _GLIBCXX_DEBUG
#else
#include <bits/stdc++.h>
#include <atcoder/all>
#define debug(...) 42
#endif

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
// ベクターのデバッグ出力
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { for (ll i = 0; i < (ll)v.size(); i++) { os << v[i] << " "; } return os;}
const ll INF = 1LL << 60;
const ll mod = 998244353;
using namespace atcoder;
using mint = modint998244353;
using Graph = vector<vector<ll>>;
// struct Edge {ll to;};
struct Edge {ll to; ll cost;};
// struct Edge {
//     int u, v, weight;
//     Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
// };
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
ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }

// using S = long long;
// using F = long long;
// ll ID = INF;
// S op(S a, S b){ return std::max(a, b); } //中身で何を求めるか
// S e(){ return -INF; }
// S mapping(F f, S x){ return f+x; }
// F composition(F f, F g){ return f+g; }
// F id(){ return ID; }

int main() {
    ll n, k; cin >> n >> k;
    Graph G(n);
    rep(i,0,n-1){
        ll a, b; cin >> a >> b;
        G[--a].emplace_back(--b);
        G[b].emplace_back(a);
    }
    vl v(k); cin >> v;
    set<ll> vk;
    rep(i,0,k) vk.insert(--v[i]);

    ll ans = n;

    rep(i,0,n){
        if(vk.count(i)) continue;
        ll cnt = 0;
        for(cauto nv : G[i]){
            if(vk.count(nv)) cnt++;
        }
        if(cnt <= 1) ans--; 
    }
    cout << ans << endl;

    // set<ll> used;
    // vl seen(2e6);


    // queue<ll> q;
    // q.push(v[0]);
    // vl dist(n, INF);
    // while(not q.empty()){
    //     ll cv = q.front(); q.pop();
    //     for(cauto nv : G[cv]){
    //         if(dist[nv] == INF){
    //             dist[nv] = dist[cv] + 1;
    //             q.push(nv);
    //         }
    //     }
    // }
    // vl dist2;
    // rep(i,0,k) dist2[i] = dist[v[i]];
    // ll ma = *max_element(all(dist2));
    





    // seen[v[0]] = 1;
    // used.insert(v[0]);
    
    // ll cnt = 0;
    int subtree_size = 0;
    bool required[2000000];  
    bool in_subtree[2000000]; 

    auto f = [&](auto f, ll cv) -> ll {

        ll subtree_size = 0;
        in_subtree[cv] = required[cv]; 
        for (ll u : G[cv]) {
            if (u == cv) continue;
            subtree_size += f(f, u, v);
            in_subtree[v] |= in_subtree[u]; 
        }
        if (in_subtree[v]) {
            subtree_size++; 
        }
        return subtree_size;
    };
    fill(required, required + n, false);
    rep(i,0,k){
        required[v[i]] = true;
    }
    f(0, -1);
    cout << subtree_size << endl;
    // cout << ans << endl;



    return 0;
}