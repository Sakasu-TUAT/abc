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
	int h,w; cin >> h >> w;
	vector<vector<char>> a(h, vector<char>(w));
	rep(i,0,h){
		rep(j,0,w){
			cin >> a[i][j];
		}
	}
	vector<int> ans(h*w);
	rep(i,0,w){
		int cnt = 0;
		rep(j,0,h){
			if(a[j][i]=='#'){
				cnt++;
			}
		}
		cout << cnt << " ";
	}
	// for(auto &v : ans){
	// 	cout << v << " ";
	// }
}
