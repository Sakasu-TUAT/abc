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
    int n = 8;
    int b;
    rep(i,0,n){
        int a; cin >> a;
        if(a%25!=0 or !(100<=a and a<=675)){
            cout << "No" << endl;
            return 0;
        }
    
        if(i!=0 and b>a) {
            cout << "No" << endl;
            return 0;
        }
        b=a;
    }
    cout << "Yes" << endl;
    return 0;
}