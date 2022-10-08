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
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
using ll = long long;
using P = pair<string,string>;
// const ll mod = 10e9+7;

template<class T> inline bool chmin(T& a,T b) {if(a>b){a=b;return 1;} return 0;}


ll n; 
int main(){
	int x,y,z; cin>>x>>y>>z;
	if(x*y<0) {cout << abs(x) << endl; return 0;}
	//以降xとyが同じ方向
	else if(abs(x)<abs(y)) {cout << abs(x) << endl; return 0;}
	else if(abs(x)>abs(y) and x*z>0 and abs(z)<abs(y)) {cout << abs(x) << endl; return 0;} //z,y,x同じ方向
	else if(abs(x)>abs(y) and x*z<0) {cout << abs(x)+2*abs(z) << endl; return 0;}
	else {cout << -1 << endl; return 0;}

}
