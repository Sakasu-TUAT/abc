#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)

template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}

const ll INF = 1e9;
const ll mod = 1000000007;


int main(){
    int n; cin >> n;
    ll ans = 0;
    rep(i,1,7*(n)+1){
        ll a; cin >> a;
        ans+= a;
        if(i%7==0){
            cout << ans << " ";
            ans  = 0;
        }
    }
    cout << endl;
  
    // cout <<ans <<  endl;
    return 0;
}