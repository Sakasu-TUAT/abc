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
  ll a, b, c; cin >> a >> b >> c;
  ll c_bit_num = __builtin_popcountll(c);
  cerr << c_bit_num << endl;
  ll x = 0, y = 0;
  if(a+b < __builtin_popcountll(c)){
    cout << -1 << endl;
    return 0;
  }
  if(c_bit_num % 2 == 0){
    if(a%2==0 and b%2==0){
      if(a!=b and min(a, b)!=0){
        cout << -1 << endl;
      } else {
        ll l = c_bit_num/2;
        ll r = l + 1;
        string x = "", y="";
        rep(i,0,a+b){
            if(a < b){
              if(i<=a){
                x+="1";
                y+="0";
              } else {
                x+="0";
                y+="1";
              }
            } else {
              if(i<=b){
                x+="0";
                y+="1";
              } else {
                x+="1";
                y+="0";
              }
            }
        }
      }
    } else if(a%2==0 and b%2!=0){
      cout << -1 << endl;
      return 0;
    } else if(a%2!=0 and b%2==0){
      cout << -1 << endl;
      return 0;
    } else if(a%2!=0 and b%2!=0){
      
    }

  } else {
    if(a%2==0 and b%2==0){
      ll l = c_bit_num/2;
      ll r = l + 1;
    } else if(a%2==0 and b%2!=0){

    } else if(a%2!=0 and b%2==0){
      
    } else if(a%2!=0 and b%2!=0){

    }
  }

  cout << bitset<64>(x).to_ulong() << " " << bitset<64>(y).to_ulong() << endl;

}