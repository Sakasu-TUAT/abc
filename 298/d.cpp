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
using namespace std;
#define Out(x) cout << x << endl
#define Yes "Yes"
#define No "No"
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
using ll = long long;
using P = pair<int, int>;
// const ll mod = 10e9+7;


int main(){
	ll n, q;
    cin >> n >> q;
    vector<vector<int>> box(200010, vector<int>());
    vector<set<int>> num(200010);
    while(q--){
        ll x; cin >> x;
        if(x==1){
            ll i, j;
            cin >> i >> j;
            box[j].emplace_back(i);
            num[i].insert(j);
        }
        if(x==2){
            ll i; cin >> i;
            sort(box[i].begin(), box[i].end());
            for(const auto &v : box[i]){
                cout << v << " ";
            }
            cout << endl;
        }
        if(x==3){
            ll i; cin >> i;
            for(const auto &v : num[i]){
                cout << v << " ";
            }
            cout << endl;
        }
    }
}