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
	int n,m; cin>>n>>m;
	vector<multiset<int>> ans(n); 
	rep(i,0,m){
		int a, b; cin>>a>>b;
		ans[a-1].insert(b);
		ans[b-1].insert(a);
	}
	rep(i,0,n){
		int cnt=0;
		for(auto &v : ans[i]){
			if(v!=0)cnt++;
		}
		cout << cnt << " ";
		for(auto &v : ans[i]){
			if(v!=0)cout << v <<" ";
		}
		cout << endl;
	}
	
}
