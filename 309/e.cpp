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
const ll mod = 998244353;

int main(){
    ll n, m; cin >> n >> m;
    // dp[i][j] := i人目までに整数を渡す方法で、
    // j=0のとき、0人目に渡す整数とi人目に渡す整数が異なる方法の通り数
    // j=1のとき、0人目に渡す整数とi人目に渡す整数が等しい方法の通り数
    // vector<int> 
    
    

    return 0;
}