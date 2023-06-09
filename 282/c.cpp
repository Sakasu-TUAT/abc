#include <bits/stdc++.h>
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
using P = pair<ll, ll>;
// const ll mod = 10e9+7;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

struct Edge {
    int to;
};
using Graph = map<int,vector<Edge>>;
map<int, bool> seen;  // 探索したか記録

void dfs(Graph G, int v) {
    seen[v] = true;
    for (auto e : G[v]) {
        if (!seen[e.to]) {  // 訪問済みでなければ探索
            dfs(G, e.to);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    Graph G;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back({v});
        G[v].push_back({u});
    }
    int cnt = 0; 
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            dfs(G, i);
            cnt++; // dfsした回数をカウント
        }
    }
    cout << cnt << endl;
    return 0;
}