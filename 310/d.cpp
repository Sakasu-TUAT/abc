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
#include <algorithm>

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
const ll mod = 1000000007;
int dx[4] = {1, 0, 0, -1}; 
int dy[4] = {0, 1, -1, 0}; 

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template <class T, class U> bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U> bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
template <class Head, class... Tail> void in(Head&& head, Tail&&... tail) {cin >> head;in(std::forward<Tail>(tail)...);}
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
vector<bool> Eratostenes(int n){ vector<bool> isprime(n+1, true);isprime[1] = false; rep(p,2,n+1){ if(!isprime[p]) continue; for(int q = p*2; q <= n; q+=p){ isprime[q] = false; }} return isprime;}
ll power(ll a, ll b) { ll ans = 1;for(ll i=0; i<60; i++){if(b & (1LL<<i)) {ans *= a;ans %= mod;}a *= a;a %= mod;}return ans;}
ll combination(ll n, ll k){ assert(!(n < k)); assert(!(n < 0 || k < 0)); ll s = 1, t = 1; rep(i,1,k+1){ s = s*(n-i+1) % mod; t = t*i % mod; } return s * power(t, mod-2) % mod;}


int main(){
    int n, t, m;
    cin >> n >> t >> m;
 
    vector ng(n+1, vector<int>(n+1, false));
    rep(i,0,m){
        int a, b; cin >> a >> b;
        ng[a][b] = ng[b][a] = true;
    }

    ll ans = 0;
    vector<vector<int>> team;
    auto dfs = [&](auto dfs, int now) -> void {
        if(now == n+1  and team.size() == t){
            ans++;
        }
        if(team.size() > t or now > n) return;
        rep(i,0,team.size()){
            //　ngの組み合わせをチェック
            bool f = false;
            for(const auto v : team[i]){
                f |= ng[v][now];
            }
            if(f) continue; //ここまで

            //team[i]にngのペアがいなかった場合、team[i]にそのまま追加
            team[i].emplace_back(now);
            dfs(dfs, now+1);
            team[i].pop_back();
        }
        team.push_back(vector{now}); //新たなチームを作成
        dfs(dfs, now + 1);
        team.pop_back();
    };

    dfs(dfs, 1);

    cout << ans << endl;

    return 0;
}