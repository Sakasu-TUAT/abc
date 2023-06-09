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

int main(){
    int n; cin>>n;
    vector<ll> p(n),a(n);
    rep(i,0,n){cin>>p[i];a[i] = p[i];}
    int cnt=0, k=0;
    do {
        if(cnt==1){
            for(auto x : p) cout << x << " "; cout << "\n";
            return 0;
        } 
        cnt++;
    } while (prev_permutation(p.begin(), p.end()));
    return 0;
}