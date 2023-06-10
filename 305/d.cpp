#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    enum class Pattern{
        odd,
        even
    };
    map<ll, Pattern> mp;
    
    vector<ll> a(n+1), sleepTime(n+1);
    ll x; 
    Pattern p = Pattern::odd;
    rep(i,1,n+1){
        cin >> a[i];
        mp[x] = p;
        if(p==Pattern::even){
            sleepTime[i] = sleepTime[i-1] + a[i];
        } else {
            sleepTime[i] = sleepTime[i-1];
        }
        p = (p==Pattern::odd) ? Pattern::even : Pattern::odd;
    }
    
    int q; cin >> q;
    rep(i,0,q){
        ll l, r; cin >> l >> r;   
        auto l_pos = lower_bound(a.begin(), a.end(), l); 
        auto l_idx = distance(a.begin(), l_pos);
        cout << "vec[" << l_idx << "] = " << *l_pos << "\n";
        auto r_pos = lower_bound(a.begin(), a.end(), r);
        auto r_idx = distance(a.begin(), r_pos);
        cout << "vec[" << r_idx << "] = " << *r_pos << "\n";
        cerr << "ans: " << sleepTime[r_idx] - sleepTime[l_idx] << endl;
    }
    return 0;
}