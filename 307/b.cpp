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

bool kaibun(string s){
    rep(i,0,s.length()/2){
        if(s[i]!=s[s.length()-i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    ll n; cin >> n;
    vector<string> s(n);
    rep(i,0,n){
        cin >> s[i];
    }
    rep(i,0,n){
        rep(j,0,n){
            if(i==j) continue;
            if(kaibun(s[i]+s[j])){
                cerr << s[i] + s[j] << endl;
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}