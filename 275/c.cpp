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

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

struct Graph{
    int x,y;
    Graph(int x, int y): x(x), y(y){}
};

int main(){
    vector<string> s(9);
    rep(i,0,9){
        cin >> s[i];
    }
    vector<vector<Graph> G();
    rep(i,0,9){
        rep(j,0,9){
            rep(k,0,9){
                if(s[i][j]=='#'){
                    G[(i,j)].emplace_back(i,j);
                }
            }
        }
    }

    return 0;
}