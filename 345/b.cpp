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

#define N (1 << 19)

int main(){
  ll n, h, w; cin >> n >> h >> w;
  vector<P> tile(n);
  for(auto &[k, v] : tile) cin >> k >> v;
  vvl board(h, vl(w, -1));
  auto f = [&](auto f, ll bit, ll y, ll x) -> bool {
    if(x==w){
      x=0;
      y++;
    }
    if(y==h) return true;
    if(board[y][x]!=-1) return f(f, bit, y, x+1);
    rep(i,0,n) {
      if(bit & (1LL<<i)) continue;
      auto &[ty, tx] = tile[i];
      vector<P> pos = {{ty, tx}, {tx, ty}};
      for(cauto [p, q] : pos){
        if(y+p > h or x+q > w) continue;
        bool ok = true;
        rep(dy, 0, p){
          rep(dx, 0, q){
            if(board[y+dy][x+dx] != -1) ok = false;
          }
        }
        if(!ok) continue;
        rep(dy, 0, p){
          rep(dx, 0, q){
            board[y+dy][x+dx]=i;
          }
        }
        if(f(f, bit | (1LL<<i), y, x+1)) return true;
        rep(dy, 0, p){
          rep(dx, 0, q){
            board[y+dy][x+dx]=-1;
          }
        }
      }
    }
    return false;
  };
  if(f(f, 0, 0, 0)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}