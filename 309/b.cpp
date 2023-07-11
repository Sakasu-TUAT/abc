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
    vector<string> a(n);
    rep(i,0,n) { 
        cin >> a[i];
    }
    vector<int> b;
    rep(i,0,n) rep(j,0,n){
        if(i==0){
            if(j==0) cout << a[i+1][0];
            else {cout << a[i][j-1];}
            if(j==n-1){cout << endl;}
        } else if(i!=n-1){
            if(j==0){cout << a[i+1][j];}
            else if(j==n-1) cout << a[i-1][j] << endl;
            else cout << a[i][j];
        } else if(i==n-1){
            if(j!=n-1){cout << a[i][j+1];}
            else cout << a[i-1][n-1];
        }
    }



    return 0;
}