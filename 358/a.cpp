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
using Graph = vector<vector<ll>>;
int main() {
    ll k; cin >> k;
    vl c(26);  cin >> c;
    mint ans = 0;
    ll m = 26;
    //dp[i][j][k]:= 長さiで文字jをk回使った時の数
    vector<vector<vector<mint>>> dp(k, vector<vector<mint>>(m, vector<mint>(m, 0)));
    dp[0][0][0] = 1;
    rep(len, 1, k+1){  //長さlen
        rep(i, 0, m){ //文字i
            rep(j, i, m){  //文字j
                if(len <= c[i]){
                    dp[len][i][i] += dp[len-1][i][j-1];
                }
            }
        }
    }
    rep(i, 0, k){
        rep(j, 0, m){
            rep(k, 0, m){
                if(k > c[j]) continue;
                ans += dp[i][j][k];
            }
        }
    }
    cout << ans.val() << endl;



    
    
    return 0;
}