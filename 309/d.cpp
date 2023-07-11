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

int n1, n2, m;
vector<vector<int>> graph((n1+n2), vector<int>(m));

int bfs(int s){
    vector<int> dist(graph.size(), -1);
    queue<int> que;
    dist[s] = 0;
    que.push(s);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(const auto next : graph[now]){
            if(dist[next] == -1) {
                dist[next] = dist[now] + 1;
                que.push(next);
            }
        }
    }
    return *max_element(dist.begin(),dist.end());
}


int main(){
    cin >> n1 >> n2 >> m; 
    graph.resize((n1+n2));
    rep(i,0,m){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    cout << bfs(0) + bfs(n1+n2-1) + 1 << endl;
    return 0;
}