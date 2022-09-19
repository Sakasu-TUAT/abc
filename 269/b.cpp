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
	vector<string> table(11);
	rep(i,0,10){
		cin >> table[i]; 
		cerr << table[i] << endl;
	}
	ll a,b,c,d;
	rep(i,0,10){
		rep(j,0,10){
			if(table[i][j] == '#'){
				a = i+1;
				c = j+1;		
				break;
			}
		}
	}
	for(int i=9; i>=0; --i){
		for(int j=9; j>=0; --j){
			if(table[i][j] == '#'){
			b = i+1;
			d = j+1;	
					cout << a << " "<<b << endl;
	cout << c <<" " <<  d << endl;
	return 0;
			}
		}
	}



}
