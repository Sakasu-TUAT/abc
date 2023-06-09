#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

unordered_map<int, bool> memo;
unordered_map<int, bool> visited;
using Graph = unordered_map<int, vector<int>>;
Graph G;
bool dfs(int s){
    memo[s] = true; //探索した全頂点を記録
    if(visited[s]) {
        cerr << "visited" << endl;
        return true; 
    }
    bool closed = false;
    visited[s] = true;
    for(auto next : G[s]){
        if(visited[next]) continue;
        if(dfs(next)) closed = true;
    }
    visited[s]=false;
    return closed;
}

int main() {
    int n,m; 
    cin >> n>> m;
    dsu d(1000009);
    int ans = 0;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        u--; v--;

        if(!d.same(u,v)){
            d.merge(u,v);
        } else {
            ans++;
        }
    }
    
    cout << ans << endl;

    
    return 0;
}