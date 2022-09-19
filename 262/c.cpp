#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
using namespace std;
// #define rep(i,n) for(ll i=0; i<(n); ++i)
#define Out(x) cout << x << endl
#define Yes "Yes"
#define No "No"
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)
#define fore(i, a) for (auto &i : a)
using ll = long long;
using P = pair<int, int>;
// const ll mod = 10e9+7;


int main(){
	int n;cin>>n;
    vector<int> a(n);
    int sameNum=0;
    rep(i,0,n){
        cin>>a[i]; a[i]-=1;
        if(a[i]==i) sameNum+=1;
    };
    ll ans = sameNum*(sameNum-1)/2;
    rep(i,0,n){
        if(a[i]>i and a[a[i]]==i){
            ans+=1;
        }
    }
    cout << ans << endl;
    return 0;
}