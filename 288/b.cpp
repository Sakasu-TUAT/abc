#include <iostream>
#include <string>
#include <map>
#include <set>
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
	int n, k;
	cin>>n>>k;
	vector<string> a;
	rep(i,0,n){
		string s; cin >> s;
		if(i>=k) continue;
		a.emplace_back(s);
	}
	sort(a.begin(), a.end());
	for(auto b : a){
		cout << b  << endl;
	}
	return 0;
}
