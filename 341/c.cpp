#include <bits/stdc++.h>

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

using Graph = vvl;
#include <atcoder/all>
using namespace atcoder;
int main(){
  ll n, d; cin >> n >> d;
  vl a(n); cin >> a;
  set<ll> st;
  dsu dsu(10);
  st.insert(a[0]);
  Graph G(10);
  rep(i,0,n){
    auto l_it = st.lower_bound(a[i]-d);
    auto r_it = st.upper_bound(a[i]+d);
    r_it--;
    if(l_it != st.end()) {
        cerr << *l_it << ", " << a[i] << endl;
        dsu.merge(a[i], *l_it);
        G[*l_it].emplace_back(a[i]);
    }
    if(*r_it - a[i] <= d) {
        cerr << *r_it << ", " << a[i] << endl;
        dsu.merge(a[i], *r_it);
        G[a[i]].emplace_back(*r_it);
    }
    st.insert(a[i]);
  }
  cerr << "Graph" << endl;
  rep(i,0,n){
    cerr << a[i] << "->";
    for(cauto v : G[a[i]]){
        cerr << v << " ";
    } cerr << endl;
  }
//   for(cauto v : dsu.groups()){
//     if(v.size()==1) continue; 
//     for(cauto e : v){
//         cerr << e << " ";
//     }cerr << endl;
//   }



  return 0;
}
