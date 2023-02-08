#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)

using  Graph = unordered_map<string, vector<string>>;
Graph G;
unordered_map<string, bool> memo;
unordered_map<string, bool> visited;
queue<string> que;

bool bfs(string s){
    que.push(s);
    while(!que.empty()){
        string t = que.front();
        que.pop();
        for(auto v : G[t]){
            memo[v] = true;
            if(visited[v]) return true;
            visited[v] = true;
            que.push(v);
        }
    }
    return false;
}

int main(){
    int n; cin>>n;
    vector<string> s(n), t(n);

    unordered_map<string, int> m;
    rep(i,0,n){
        cin >> s[i] >> t[i];
        G[s[i]].emplace_back(t[i]);
    }
    rep(i,0,n){
        if(memo[s[i]]) continue;
        bool closed = bfs(s[i]);
        if(closed) {
            cout << "No" << endl;
            return 0;
        }
        visited.clear();
    }
    cout << "Yes" << endl;
 
    return 0;
}