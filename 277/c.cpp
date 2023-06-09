#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
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

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};


int main(){
    ll n; cin>>n;
    //グラフをmapでもっておくと楽
    map<ll, vector<ll>> graph;
    rep(i,0,n){
        int a,b; cin>>a>>b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    queue<ll> que;
    que.push(1);
    set<int> S;
    S.insert(1);
    //幅優先探索->1に隣接している頂点を順に調べる
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(auto i : graph[v]){ //i:=vに隣接している要素
            //まだiが未探索である場合
            if(!S.count(i)){
                que.push(i); //探索の順番待ち
                S.insert(i);
            }
        }
    }
    //setは昇順に格納してくれているので、最後の値が1から辿れる最大値
    cout << *S.rbegin() << endl;
    return 0;
}
