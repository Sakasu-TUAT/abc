#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = a; i < b; i++)


int main(){
    ll n,k; cin>>n>>k;
    vector<ll> a(n), s(n+1);
    s[0] = 0;
    rep(i,0,n){
        cin >> a[i];
        if(i>=1){
            s[i] = a[i]-a[i-1] + s[i-1]; //差分の累積和
        }
    }
    int q; cin >> q;
    rep(i,0,q){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(abs(s[r]-s[l])%k == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}