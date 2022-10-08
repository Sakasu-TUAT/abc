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
	ll n,q; cin>>n>>q;
	vector<ll> a(n+1, 0), L(n+1, 0);
	ll lcount=0, acnt=0;
	ll cnt=0;
	while(1){
		if(cnt==0){
			ll c;cin>>c;
			cerr << "C: " << c << endl;
			L[lcount] += (c);
			cerr << "lcount: "<<lcount << " / " << "L[lcount]: " << L[lcount] << endl;
			lcount++;
		}
		else if(cnt == L[lcount-1]){
			ll c;cin>>c;
			cerr << "C: " << c << endl;
			L[lcount] = L[lcount-1]+(c);
			cerr << "lcount: "<<lcount << " / " << "L[lcount]: " << L[lcount] << endl;
			lcount++;
		}
		cin >> a[acnt];
		cerr << a[acnt];
		acnt++;
		cnt++;
		if(cnt > l[n]){break;}
	}
	rep(i,0,q){
		ll s,t; cin>>s>>t; s--;t--;
		cout << a[L[s]+t];
	}
	return 0;
}
