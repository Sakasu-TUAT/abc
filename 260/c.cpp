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
#define Yes "Yes"
#define No "No"
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
using ll = long long;
using P = pair<long, char>;
// const ll mod = 10e9+7;

int main(){
	ll n, x, y; cin >> n >> x >> y;
	vector<ll> r(12), b(12);
	r[1]=0; b[1]=1;
	rep(i,2,n+1){
		b[i] = r[i-1]+ y*b[i-1];
		r[i] = r[i-1]+ x*b[i];
	}
	cout << r[n] << endl;
}