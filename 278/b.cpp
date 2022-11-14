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
	int n; cin>>n;
	vector<string> a(n);
	rep(i,0,n){
		string s; cin>>s;
		if(!(s[0]=='H' or s[0]=='D' or s[0]=='C' or s[0]=='S')){
			cout << "No" << endl;
			return 0;
		}
		if(!(s[1]=='A' or s[1]=='2' or s[1]=='3' or s[1]=='4' or s[1]=='5' or s[1]=='6'
		 	or s[1]=='7' or s[1]=='8' or s[1]=='9'  or s[1]=='T' or  s[1]=='J' or s[1]=='Q' or s[1]=='K')){
			cout << "No" << endl;
			return 0;
		}
		a[i] = s;
	}
	if(n==1){
		cout << "Yes" << endl;
		return 0;
	}
	rep(i,0,n-1){
		rep(j,i+1,n){
			if(a[i]==a[j]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
		cout << "Yes" << endl;
		return 0;
}
