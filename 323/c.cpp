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

int main() {
    ll n,m; cin >> n >> m;
    vll a(m), score(n);
    vector<pair<ll, ll>> b(m);
    vector<vector<bool>> solved(n, vector<bool>(m, false));
    vector<bool> ok(n);
    bool allBatsu = true;
    
    rep(i,0,m) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(rall(b));
    // rep(i,0,m){cerr << b[i].first << " \n"[i==n];}
    // cerr << "------\n";
    map<ll, ll> mp;
    ll currentMax = 0;
    rep(i,0,n){
        string s; cin >> s;
        ll tmp = 0;
        rep(j,0,m){
            if(s[j]=='o') {
                tmp+=(a[j]);
                solved[i][j] = true;
                ok[i] = true;
                allBatsu = false;
            }
        }
        if(ok[i]) tmp+=(i+1); //一問でも解いていたらボーナス付与
        chmax(currentMax, tmp);
        score[i] = tmp;
        mp[tmp]++;
    }
    rep(i,0,n){
        
        // cerr << i+1  << "'s score is " << score[i] << endl;
        if(allBatsu){
            cout << 1 << endl;
            continue;
        }
        if(score[i] == b[i].second and mp[score[i]]==1) {
            cout << 0 << endl;
            continue;
        }
        if(!ok[i]) { //一問も解いてない
            score[i] += (i+1); //初めてボーナス点を付与
            ok[i] = true;
        }
        ll cnt = 0;
        rep(j,0,m){
    
            if(solved[i][b[j].second]) continue;
            score[i] += b[j].first;
            if(score[i] > currentMax){
                cout << cnt+1 << endl;
                break;
            }
            cnt++;
            // cerr << score[i] << endl;
        }
    }


}


