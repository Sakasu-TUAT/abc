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

int main(){
	// int x,k; cin >> x >> k;
	string x; int k;
	cin >> x >> k;
	char num[11] = {'0','1','2','3','4','5','6','7','8','9','0'};
	rep(i,0,k){
		int n=x.length()-1;
		if(i>n)break;
		if(x[n-i] >= '5'){
			x[n-i]='0';
			x[n-i-1]=num[x[n-i-1]-'0'+1];
			cout << x[n-i] <<" : "<< x[n-i-1] << endl;
		} else {
			x[n-i]='0';
		}
	}
	cout << x << endl;
	
}
