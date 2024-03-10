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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9+7;

struct Node {
    int max1, max2, count;
};

vector<int> a;
vector<Node> seg;

void build(int id, int l, int r) {
    if (r - l == 1) {
        seg[id] = {a[l], -INF, 1};
        return;
    }
    int mid = (l + r) / 2;
    build(2*id, l, mid);
    build(2*id+1, mid, r);
    seg[id].max1 = max(seg[2*id].max1, seg[2*id+1].max1);
    seg[id].max2 = max(min(seg[2*id].max1, seg[2*id+1].max1), max(seg[2*id].max2, seg[2*id+1].max2));
    seg[id].count = (seg[2*id].max1 == seg[id].max1 ? seg[2*id].count : 0) + (seg[2*id+1].max1 == seg[id].max1 ? seg[2*id+1].count : 0);
}

Node query(int x, int y, int id, int l, int r) {
    if (r <= x || y <= l) return {-INF, -INF, 0};
    if (x <= l && r <= y) return seg[id];
    int mid = (l + r) / 2;
    Node left = query(x, y, 2*id, l, mid);
    Node right = query(x, y, 2*id+1, mid, r);
    Node res;
    res.max1 = max(left.max1, right.max1);
    res.max2 = max(min(left.max1, right.max1), max(left.max2, right.max2));
    res.count = (left.max1 == res.max1 ? left.count : 0) + (right.max1 == res.max1 ? right.count : 0);
    return res;
}

int query_second_max_count(int l, int r) {
    Node res = query(l, r, 1, 0, a.size());
    return res.max2 == res.max1 ? res.count : 0;
}



int main(){
    ll n, q; cin >> n >> q;
    vl a(n);
    cin >> a;
    while(q--){
        int b; cin >> b;
        if(b==1){
            ll p, x; cin >> p >> x;
        } else {
            ll l, r; cin >> l >> r;
            
        }
    }
}