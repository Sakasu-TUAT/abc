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
	string s; cin >> s;
	bool first = false, second = false;
	vector<int> a(7);
	a[0] = s[6]-'0';
	a[1] = s[3] -'0';
	a[2] = s[1]+s[7] -'0' -'0';
	a[3] = s[0]+s[4] -'0' -'0';
	a[4] = s[2]+s[8]-'0' -'0';
	a[5] = s[5] -'0';
	a[6] = s[9] -'0';
	
	if(s[0]=='0'){
		rep(i,0,4){
			for(int j=i+1; j<6; j++){
				for(int k=j+1; k<7; k++){
					cerr << a[i] <<":" << a[j] << ":" << a[k] << endl; 
					if(a[i]!=0 && a[j]==0 && a[k] !=0){
						cout << "Yes" << endl;
						return 0; 
					}
				}
			}
		}
	} 
	cout << "No"<< endl;
    return 0;
}
