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
using P = pair<int, int>;
// const ll mod = 10e9+7;


int main(){
	int n;
    vector<int> p(n);
    rep(i,0,n){
        cin >> p[i];
    }
    ll ans = -1;
    rep(i,0,n){
        if(i==0){
            if(p[i]==i || p[i] == (i+1%n)){
                
            }
        }
        if(p[i]==mod(i-1, n))
    }

}