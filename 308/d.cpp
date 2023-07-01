#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cassert>

using namespace std;
using ll = long long;
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)

template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}


const ll INF = 1e9;
const ll mod = 1000000007;
const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};
const vector<pair<int, int>> dxy = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i,0,h) cin >> s[i];
    map<char, char> next = {
        {'s', 'n'},{'n', 'u'},{'u', 'k'},{'k', 'e'},{'e', 's'}
    };
    vector visited(h+1, vector<bool>(w+1));

    auto dfs = [&](auto &dfs, int i, int j) -> void {
        visited[i][j] = true;
        for(const auto [dx, dy]: dxy){
            int ni = i+dy, nj=j+dx;
            if(!(0<=ni and ni<h and 0<=nj and nj<w)) continue;
            if(visited[ni][nj]) continue;
            if(s[ni][nj]==next[s[i][j]]){
                dfs(dfs, ni, nj);
            }
        }
    };

    dfs(dfs, 0, 0);
    cout << (visited[h-1][w-1] ? "Yes" : "No") << endl;    
    return 0;
}