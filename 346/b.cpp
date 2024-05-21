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
  ll n; cin >> n;
  string t; cin >> t;
  string s; 
  s = "d";
  s+=t;
  cerr << s << endl;
  vl c(n+1); rep(i,1,n+1) cin >> c[i];
  vvvl dp(n+2, vvl(2, vl(2, 100)));
  if(s[1]==s[2]){
    // dp[1][(s[1]-'0')][1] = c[1];
    dp[2][(s[1]-'0')][1] = c[1];
  }  
  //dp[i][j][k]:=s[i]までみたとき、i番目の数字がjで状態がk(k=1なら良い文字列)であるときの最小コスト
  //ans. min(dp[n][0][1],dp[n][1][1]); 
  rep(i,1,n+1){
      if(s[i]=='0'){
        chmin(dp[i+1][0][1], dp[i][0][0]); //000->000
        chmin(dp[i+1][0][0], dp[i][0][1]); //100->100
        chmin(dp[i+1][1][0], dp[i][0][1] + c[i]); //000->010
        chmin(dp[i+1][1][1], dp[i][0][0] + c[i]); //100->110
      } if(s[i]=='1'){
        chmin(dp[i+1][1][1], dp[i][1][0]); //011->011
        chmin(dp[i+1][1][0], dp[i][1][1]); //111->111
        chmin(dp[i+1][0][0], dp[i][1][1]+c[i]); //111->101
        chmin(dp[i+1][0][1], dp[i][1][0]+c[i]); //011->001
      } 
     }
     cerr << i << ": "; 
      rep(j,0,2){
        rep(k,0,2){
          cerr << dp[i][j][k] << " "; 
        }
      }
      cerr << endl;
  }
  rep(k,1,n+2){
    rep(i,0,2){
      rep(j,0,2){
        cerr << dp[k][i][j] << "\t"; 
      }
    }
    cerr << endl;
  }
  
  cout << min(dp[n][0][1], dp[n][1][1]) << endl;



}