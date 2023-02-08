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
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
using ll = long long;
using P = pair<string, string>;
// const ll mod = 10e9+7;


int main(){
    int n,x; cin>>n>>x;
    queue<int> ans;
    rep(i,0,n){
        int a; cin>>a;
        ans.push(a);
    }
    rep(i,0,x){
        ans.pop();
        ans.push(0);
    }
    rep(i,0,n){
        int a = ans.front();
        ans.pop();
        cout << a << " ";
    }
    return 0;
}