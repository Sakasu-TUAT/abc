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
#include <cinttypes>
#include <algorithm>
#include <cstdlib>
#include <atcoder/all>
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<ll, ll>;
using vll = vector<ll>;
using vi = vector<int>;

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
const ll INF = 1LL << 60;
// const ll mod = 1000000007;
const ll mod = 998244353;
using Graph = vector<vector<ll>>;


/* encode: ランレングス圧縮を行う
*/
vector<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
/* decode: ランレングス圧縮の復元を行う
*/
string decode(const vector<pair<char, int>>& code) {
    string ret = "";
    for (auto p : code) {
        for (int i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}

const ll dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const ll dy[8] = {0, 1, -1, 1, -1, 0, 1, -1};

int main() {
    ll h, w; cin >> h >> w; 
    vector<string> vec(h);
    rep(i,0,h) {cin >> vec[i];}

    auto ok = [&](P nx){
        return (
            nx.first>= 0 and nx.first<=h-1 and 
            nx.second>= 0 and nx.second<=w-1 and 
            vec[nx.first][nx.second] == '#'
        );
    };
    ll ans = 0;
    vector<vector<bool>> visited(h*2, vector<bool>(w*2));
    rep(i,0,h){
        rep(j,0,w){
            if(vec[i][j] == '.') continue;
            if(visited[i][j]) continue;
            queue<P> que;
            que.push({i, j});
            while(!que.empty()){
                auto cur = que.front();
                que.pop();
                rep(k,0,8){
                    // cerr << "i: " << i << endl;
                    P nx = {cur.first + dy[k], cur.second + dx[k]};
                    if(!ok(nx)) continue;
                    if(visited[nx.first][nx.second]) continue;
                    visited[nx.first][nx.second] = true;
                    que.push(nx);
                }
            }
            ans++;
        }
    }

 
    cout << ans << endl;


}


