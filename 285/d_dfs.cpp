#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)

int n;
unordered_map<string, bool> memo;
unordered_map<string, int> visited;
using Graph = unordered_map<string, vector<string>>;
Graph G;

bool dfs(string s){
    memo[s] = true; //探索した全頂点を記録
    if(visited[s]) return true; //既に行きがけで探索済みの頂点に再度訪れた場合、サイクルが出来ているのでtrue
    //ex. a---->b---->c---->aは  最初のaでvisited[a]=trueなので、
    //    a---->b---->c 二回目のaではサイクルができる
    //    ^-----------|
    bool closed = false;
    //行きがけの往路だけtrueにしておく
    //a----->b  visited[b] = true;
    visited[s] = true;
    for(auto t : G[s]){
        if(dfs(t)) closed = true;
    }
    //行きがけの復路はfalse
    //a----->b  visited[b] = false;
    //^------| return
    visited[s]=false;
    return closed;
}

int main(){
    cin>>n;
    vector<string> s(n), t(n);
    rep(i,0,n){
        cin >> s[i] >> t[i];
        //s->tのグラフを作成
        G[s[i]].emplace_back(t[i]);
    }
    rep(i,0,n){
        string start = s[i];
        if(memo[start]) continue;  //既にdfsで探索済み頂点は無視
        bool closed = dfs(start);
        if(closed){
            cout << "No" << endl; 
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

