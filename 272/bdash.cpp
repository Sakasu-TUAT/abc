#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include<set>
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
	vector<set<int>> a(n);
	rep(i,0,m){
		int k; cin >> k;
		rep(j,0,k){
			int joiner; cin >> joiner; joiner--;
			a[joiner].insert(i);
		}
	}
	rep(i,0,n){
		    for (auto itr = a[i].begin(); itr != a[i].end(); ++itr) {
			cerr << *itr;
		}
	}
	rep(i,0,n-1){
		int cnt=0;
		rep(j,i+1,n){
			bool danced = false;
			for (auto itr = a[j].begin(); itr != a[j].end(); ++itr) {    
				if(a[i].find(*itr) != a[i].end()){
					//a[i]がa[j]とitr番目の舞踏会で踊ったことがあるとき
					danced = true;
				}                 
			}
			if(!danced){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
