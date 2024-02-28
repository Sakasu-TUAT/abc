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


int main(){
    int h, w; cin >> h >> w;
    vvl a(h, vl(w)), b(h, vl(w));
    rep(i,0,h) rep(j,0,w) {cin >> a[i][j];}
    rep(i,0,h) rep(j,0,w) {cin >> b[i][j];}
    vl ord_h(h), ord_w(w);
    iota(all(ord_h), 0);
    iota(all(ord_w), 0);
    ll ans = INF;
    do{
        do{
            bool ok = true;
            rep(i,0,h){
                rep(j,0,w){
                    if(a[ord_h[i]][ord_w[j]]!=b[i][j]) ok = false;
                }
            }
            if(ok){
                ll cnt = 0;
                int pinv = 0;
                int qinv = 0;
                rep(i,0,h) rep(j,0,h){ if(i<j and ord_h[i]>ord_h[j]) pinv++;}
                rep(i,0,w) rep(j,0,w){ if(i<j and ord_w[i]>ord_w[j]) qinv++;}
                chmin(ans, pinv+qinv);
            }
        }while(next_permutation(all(ord_w)));
    }while(next_permutation(all(ord_h)));
    cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
