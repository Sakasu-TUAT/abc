#include <bits/stdc++.h>
using namespace std;
// #define rep(i,n) for(ll i=0; i<(n); ++i)
#define Out(x) cout << x << endl
#define Yes "Yes"
#define No "No"
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
using ll = long long;
using P = pair<ll, ll>;
// const ll mod = 10e9+7;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int main() {
    string s;
    cin>>s;
    ll n = s.length();
    cerr << n << endl;
    cerr << 26*(n-1) << endl;
    string str="";

    auto njou = [](ll a, ll n){
        if(n==0){
            return ll(1);
        }
        ll b=a;
        for(int j=1; j<n; j++){
            a*=b;
        }
        return a;
    };
    ll ans=0;
    rep(i,0,n){
        ans+=(njou(26,i)*(s[n-i-1]-'A'+1));
        // cout << "njou: "<<njou(26, i) << endl;
        // cerr << "diff:  " << s[n-i-1]-'A' << endl;
    }
    cout << ans << endl;


    
    return 0;
}