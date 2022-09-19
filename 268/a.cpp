#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
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
    vector<int> a(100000,0);
    int cnt = 0;
    rep(i,0,5){
        int b;
        cin >> b;
        if(a[b]!=0) continue;
        else if(a[b]==0){
            a[b]++;
            cnt++;
            cerr << cnt <<":" <<b << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}