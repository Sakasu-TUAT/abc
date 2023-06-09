#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
using ll = long long;

int main(){
    ll x, y, z; cin >> x >> y >> z;
    string s; cin >> s;
    string t;
    bool caps = false;
    ll ans = 0;
    rep(i,0,s.length()){
        cerr << "ans : " << ans << endl;
        if(s==t){
            cout << ans << endl;
            return 0;
        }
        if(s[i] == 'A' and caps){
            if(x < z+y){
                ans += x;
            } else {
                ans += (z+y);
                caps != caps;
            }
        } else if(s[i] == 'A' and !caps){
            if(y < z+x){
                ans += y;
            } else {
                ans += (z+x);
                caps != caps;
            }
        } else if(s[i] == 'a' and caps){
            if(y < z+x){
                ans += y;
            } else {
                ans += (z+y);
                caps != caps;
            }
        } else if(s[i] == 'a' and !caps){
            if(x < z+y){
                ans += x;
            } else {
                ans += (z+y);
                caps != caps;
            }
        }
        t+=s[i];
        cout << "t: " << t << endl;
    }

    return 0;
}