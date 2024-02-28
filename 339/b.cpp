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


int main(){
    ll n; cin >> n;
    vs s(n); cin >> s;
    P p1, p2;
    bool is_found = false;
    vvl mind(2, vl(4, 0));
    rep(i,0,n)rep(j,0,n){
       if(s[i][j] == 'P')
        if(!is_found) {
            p1 = {i, j};
            is_found = true;
        } else {
            p2 = {i, j};
        } 
    }  
    auto ok = [&](int ny, int nx) -> bool {
        return (0 <= ny and ny <=n-1 and 0 <= nx and nx <=n-1 and s[ny][nx]!='#');
    };
    rep(i,0,4){
        auto [sy, sx] = p1;
        int cy = sy, cx = sx;
        rep(j,0,n){
            cy += dy[i];
            cx += dx[i];
            if(ok(cy, cx)) continue;
            else {
                cerr << cy << ", " << cx << endl;
                mind[0][i] = j; 
                break;
            }
        }
    }
    rep(i,0,4){
        auto [sy, sx] = p2;
        int cy = sy, cx = sx;
        rep(j,0,n){
            cy += dy[i];
            cx += dx[i];
            if(ok(cy, cx)) continue;
            else {
                cerr << cy << ", " << cx << endl;
                mind[1][i] = j; 
                break;
            }
        }
    }
    //r->d->l->u
    rep(i,0,2){
        rep(j,0,4){
            cerr << mind[i][j] << " \n"[j==3];
        }
    }
    ll d = INF, diff = INF;
    rep(i,0,4){
        if(chmin(d, max(mind[0][i], mind[1][i]))){
            chmin(diff, max(mind[0][i], mind[1][i]) - min(mind[0][i], mind[1][i]));
        }
    }
    cerr << "d + diff: " << d<<" + " << diff <<  endl;

    rep(i,0,4){
        auto [sy, sx] = p2;
        int cy = sy, cx = sx;
        rep(j,0,n){
            cy += dy[i];
            cx += dx[i];
            if(ok(cy, cx)) continue;
            else {
                cerr << cy << ", " << cx << endl;
                mind[1][i] = j; 
                break;
            }
        }
    }

    return 0;
}
