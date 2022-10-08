#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
using namespace std;
// #define rep(i,n) for(ll i=0; i<(n); ++i)
#define Out(x) cout << x << endl
#define Yes "Yes"
#define No "No"
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
using ll = long long;
using P = pair<vector<ll>, bool>;
// const ll mod = 10e9+7;

using Graph = vector<vector<ll>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v, int end) {
    cerr <<"vを探索"<< v << endl;
    if(v==end){
        cout << end << endl;
        return;
    }
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, end); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    ll N; cin >> N;
    ll M = N-1;
    ll x,y; cin >>x>>y;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(1e6);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, x, y);
}