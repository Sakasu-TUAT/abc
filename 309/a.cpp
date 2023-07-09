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
    int a, b; cin >> a >> b;
    vector<vector<int>> tb(3, vector<int>(3));
    int cnt = 1;
    rep(i,0,3){
        rep(j,0,3){
            tb[i][j] = cnt;
            cnt++;
        }
    }
    
    rep(i,0,3){
        rep(j,0,3){
            if(tb[i][j]==a){
                if(j+1<=2)if(tb[i][j+1]==b){cout << "Yes" << endl; return 0;}
                if(j-1>=0)if(tb[i][j-1]==b){cout << "Yes" << endl; return 0;}
            }
        }
    }
    cout << "No" << endl;
    return 0;
}