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
    int n, m; cin >> n >> m;
    vector<string> c(n),d(m);
    vector<int> p(m+1);
    rep(i,0,n) cin >> c[i];
    rep(i,0,m) cin >> d[i];
    rep(i,0,m+1) cin >> p[i];
    int ans = 0;
    rep(i,0,n){
        string color = c[i];
        int index = -1;
        rep(j,0,m){
            cerr << "d[i]=" << d[j] << endl;
            if(d[j]==color) {
                index = j+1;
                break;
            }
        }
        if(index == -1) ans+= p[0];
        else ans += p[index];

        cerr << ans << ", " <<  p[index] <<  endl;
    }
    cout << ans << endl;


    return 0;
}