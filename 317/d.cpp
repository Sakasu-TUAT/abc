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
    ll h, w; cin >> h >> w;
    vector<string> s(h); 
    rep(i,0,h){
        cin >> s[i];
    }
    set<int> deleteRow;
    rep(i,0,h){
        char start = s[i][0];
        bool del = true;
        rep(j,1,w){
            if(start!=s[i][j]) del = false;
        }
        if(del){
            deleteRow.insert(i);
        }
    }
    set<int> deleteColumn;
    rep(i,0,w){
        char start = s[0][i];
        bool del = true;
        rep(j,1,h){
            if(start!=s[j][i]) del = false;
        }
        if(del){
            deleteColumn.insert(i);
        }
    }
    rep(i,0,w){
        if(deleteColumn.count(i)) continue;
        ll cnt = 0;
        bool del = false;
        map<char, ll> mp;
        ll deleteCnt=0;
        rep(j,0,h){
            char start;
            
            if(deleteRow.count(j)) {
                // cerr << j << " is continue" << endl;
                deleteCnt++;
                // mp[s[j][i]]++;
                continue;
            }
            if(cnt==0){start = s[j][i]; cnt++;}
            else if(start == s[j][i]){ del = true; } 
        }
        if(del) {
            cerr << i << " is to be deleted" << endl;
            deleteColumn.insert(i);
        }
    }
    // for(const auto &v : deleteRow){
    //     cerr << v << " ";
    // }cerr << endl;
    // for(const auto &v : deleteColumn){
    //     cerr << v << " ";
    // }cerr << endl;
    ll cnt = 0;
    rep(i,0,h){
        rep(j,0,w){
            if(deleteRow.count(i) or deleteColumn.count(j)) continue;
            else cnt++;
        }
    }
    cout << cnt << endl;

}


