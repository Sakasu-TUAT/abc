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
	int n,m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int> (n));
	rep(i,0,m){
		int k; cin >> k;
		rep(j,0,k){
			int joiner; cin >> joiner; joiner--;
			a[joiner].push_back(i);
		}
	}
	rep(i,0,n){
		sort(a[i].begin(), a[i].end());
	}

	rep(i,0,n){
		for(auto itr=a[i].begin(); itr!=a[i].end(); ++itr){
			cerr << *itr;
		}
		cerr << endl;
	}
	rep(i,0,n-1){
		rep(j,i+1,n){
			bool ok = false;
			rep(k,0,m){
				rep(l,0,m){
					if(a[i][k] == a[j][l]){
						cerr << i <<", "<< j <<", "<< k <<", "<< l <<", "<<endl;
						cerr << a[i][k] << endl;
						ok = true;
					}
				}
			}
			if(!ok){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
