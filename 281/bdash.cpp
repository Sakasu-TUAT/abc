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
#define rep(i,a,b) for(double i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
using ll = long long;
using P = pair<string,string>;
// const ll mod = 10e9+7;

template<class T> inline bool chmin(T& a,T b) {if(a>b){a=b;return 1;} return 0;}

int main(){
	cout << fixed << setprecision(15) << endl; 
	double x,k; cin >> x >> k;
	rep(i,0,k+1){
		double calcnum = x/pow(10, i);
		cerr << calcnum << "->";
		calcnum = round(calcnum);
		cerr << calcnum << endl;
		x = calcnum * pow(10,i);
		cerr << x << endl;
	}

	cout << static_cast<ll>(x) << endl;
	return 0;
}
