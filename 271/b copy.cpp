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
	bool nowSharp = false;
	bool dotNum = 0;
	rep(i,0,10){
		cin >> table[i]; 
		cerr << table[i] << endl;
	}
	ll a,b,c,d;
	bool end[4] = {false, false, false, false};
	int cnt=0;
	rep(i,0,10){
		rep(j,0,10){
			if(!nowSharp and table[i][j] == '#'){
				nowSharp = true;
				if(!end[0]){
					a = i+1;
					end[0] = true;
				}; 
				if(!end[2]){
					c = j+1;	
					end[2] = true;
				}
				cerr << a << c << endl;
			} else if(table[i][j] == '#' and j==9){
				d = 10;
				end[3] = true;
			} else if(table[i][j] == '#' and i==9){
				b = 10;
				end[1] = true;
			} else if(nowSharp and table[i][j] == '.'){
				nowSharp = false;
				if(!end[3]){
					d = j;
					end[3] = true;
				}
				cnt++;
				cerr << d << endl;
			}
		}
	}
	nowSharp = false;

	rep(i,0,10){
		rep(j,0,10){
			if(!nowSharp and table[j][i] == '#'){
				nowSharp = true;
			} else if(nowSharp and table[j][i] == '.'){
				nowSharp = false;
				if(!end[1]) {
					b = j;
					cerr <<"ここ" <<  b << endl;
					end[1] = true;
				}
				break;
			}
		}
	}
	cout << a << " "<<b << endl;
	cout << c <<" " <<  d << endl;
	
    return 0;
}
