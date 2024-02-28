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
// const ll mod = 1000000007;
const ll mod = 998244353;
// using mint = modint998244353;
using Graph = vector<vector<ll>>;
// struct Edge {ll to;};
// struct Edge {ll to; ll cost;};
// using Graph = vector<vector<Edge>>;


int main(){
    ll n, k; cin >> n >> k;
    vl a(k); cin >> a;
    if(k==1){
        cout << 0 << endl;
        return 0;
    } else if(k==2){
        cout << abs(a[1]-a[0]) << endl;
        return 0;
    }
    vl b(k, 2);
    vl diff(k);
    vector<P> d(k);
    ll maxLen = 0;
    rep(i,0,k){
        if(i==0) { d[i] = P{0,a[i+1]-a[i]};}
        else if(i==k-1) d[i] = P{a[i]-a[i-1],0};
        else d[i] = P{a[i]-a[i-1], a[i+1]-a[i]};
        // cerr << "i: " << i << " p: " << d[i].first << ", " << d[i].second << endl;
        if(i!=k-1){
            diff[i] = a[i+1]-a[i];
            chmax(maxLen, a[i+1]-a[i]);
        }
    }
    sort(all(diff));
    ll ans = accumulate(all(diff), 0);

    if((2*n-k)%2!=0){
        ll tmp = ans;
        rep(i,0,k-1){
            if(d[i].first==maxLen or d[i].second==maxLen){
                ans-=(d[i].first+d[i].second);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
