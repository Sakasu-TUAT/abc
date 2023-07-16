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
#include <functional>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<bool> Eratostenes(int n){
    vector<bool> isprime(n+1, true);isprime[1] = false;
    rep(p,2,n+1){ if(!isprime[p]) continue; for(int q = p*2; q <= n; q+=p){ isprime[q] = false; }}
    return isprime;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
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
const ll INF = 1LL << 60;
const ll mod = 1000000007;
int dx[4] = {1, 0, 0, -1}; 
int dy[4] = {0, 1, -1, 0}; 

ll power(ll a, ll b) {
    ll ans = 1;
    for(ll i=0; i<60; i++){
        if(b & (1LL<<i)) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
    }
    return ans;
}

ll combination(ll n, ll k){
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    ll s = 1, t = 1;
    rep(i,1,k+1){
        s = s*(n-i+1) % mod;
        t = t*i % mod; 
    }
    // フェルマーの小定理 a^(p-1) ≡ 1 (mod.p) (∵ gcd(a, p) = 1)
    // より、tの逆元は t^(p-2) ≡ t^(-1) (mod. p)
    return s * power(t, mod-2) % mod;
}

int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, set<int>>> vec(n+1);
    rep(i,0,n){
        int p, c; cin >> p >> c;
        vec[i].first = p;
        rep(j,0,c){
            int f; cin >> f;
            vec[i].second.insert(f);
        }
    }

    rep(i,0,n){
        rep(j,0,n){
            if(i==j) continue;
            if(vec[i].first>=vec[j].first){
                cerr << vec[i].first << ": " << vec[j].first << endl;
                int cnt = 0;
                for(const auto v : vec[i].second){
                    // if(i==3 and j==2){
                        // cerr << v << ", ";
                    if(vec[j].second.count(v)) {
                        cnt++;
                    }
                }
                if(cnt == vec[i].second.size()){
                    if(vec[i].second.size() < vec[j].second.size() 
                    or vec[i].first > vec[j].first){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}