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
	int h,m;
	cin >>h>>m;
	int a = h/10, b = h%10, c = m/10, d = m%10;
	if(0<=b*10+d and b*10+d<=59 and 0<=a*10+c and a*10+c<=23){ 
		cerr << "sonomanma" << endl;
		cout << h <<" " << m << endl;
	} else{
		while(1){
			int CAd = (d+1)/10;
			d=(d+1)%10;
			int CAc = (c+CAd)/6;
			c=(c+CAd)%6;
			int CAb=0;
			if(a==0 or a==1) {
				CAb = (b+CAc)/10;
				b=(b+CAc)%10;
			}
			else {
				CAb = (b+CAc)/4;
				b=(b+CAc)%4;
			}
			a = (a+CAb)%3; 
			// cerr << a << b << " " << c << d << endl;
			if(0<=b*10+d and b*10+d<=59 and 0<=a*10+c and a*10+c<=23){
				cout << a << b << " " << c << d;
				return 0;
			}
		}
	} 

	return 0;
}
