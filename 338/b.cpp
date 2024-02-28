#include <bits/stdc++.h>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long int;
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


vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
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
// const ll mod = 1000000007;
const ll mod = 998244353;
// using mint = modint998244353;
using Graph = vector<vector<ll>>;
// struct Edge {ll to;};
// struct Edge {ll to; ll cost;};
// using Graph = vector<vector<Edge>>;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};

vl bfs(int start, vvl G) {
    ll n = G.size();
    vector<ll> dist(n, -1);
    queue<ll> que;

    dist[start] = 0;
    que.push(start);

    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        for (ll nv : G[v]) {
            if (dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    return dist;
}


int main(){
    int n, m; cin >> n >> m;
    vl x(m); cin >> x;
    vvl G(n);
    rep(i,0,n-1){
        G[i].emplace_back(i+1);
        G[i+1].emplace_back(i);
    }
    G[0].emplace_back(n-1);
    G[n-1].emplace_back(0);

    // ll ans = INF;
    // ll len = 0;
    // ll cur = x[0];
    // rep(i,0,m){
    //     len += min(abs(x[i]-cur), (x[i]+cur)%n);
    //     cur = x[i];
    // }
    // cout << len << endl;

    // queue<ll> que;
    
    // rep(i,0,n){
    //     x[i]--;
    // }
    // vector<bool> visited(n, false);
    // auto dist = bfs(x[0], G);
    // cerr << dist[x[m-1]] << endl;
    


    return 0;
}
