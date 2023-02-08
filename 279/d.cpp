#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
#include <unordered_map>
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

unordered_map<ll, ll> memo;

// index が条件を満たすかどうか
bool isOK(double now, double mid, int a , int b) {
    if (b*now + a/sqrt(now+1) >= b*mid + a/sqrt(mid+1)) return true;
    else return false;
}

double binary_search(int a, int b) {
    ll now = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll target = 1e18; // 

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(int(now) - int(target)) > 1) {
        double mid = (now + target) / 2;
        cerr << "now: " << now << ", " << "mid: " << mid <<", tar: " << target<< "/";
        if (isOK(now, mid, a, b)) now = mid;
        else target = mid;
        cerr << "now: " << now << ", " << "mid: " << mid <<", tar: " << target<< "\n";
    }
    return now;
}


int main(){
    double a,b;
    cin >> a >> b;
    double i = binary_search(a, b);
    long double ans = b*i + a/sqrt(i+1);
    cout << ans << endl;
    return 0;
}