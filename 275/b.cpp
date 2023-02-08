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

const ll nmod = 998244353;

int main(){
	ll a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >>f;
	a=a%nmod; b=b%nmod;c=c%nmod;d=d%nmod;e=e%nmod;f=f%nmod;
	ll ans = (((((a%nmod) * (b%nmod))%nmod * (c%nmod))%nmod - (((d%nmod) * (e%nmod))%nmod * (f%nmod))%nmod)%nmod);
	if(ans < 0){
		cout << ans + nmod << endl;
	} else {
		cout << ans << endl;
	}
}
