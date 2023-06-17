#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
using ll = long long;

int main(){
    int n, k, q; cin >> n >> k >> q;
    unordered_map<ll, ll> mp;

    set<ll> st, k_st;
    ll ans = 0;
    while(q--){
        
        ll x, y; cin >> x >> y;
        st.insert(y);
        int idx = st.count(y);
        
        cerr << "st: ";
        for(const auto &v : st){
            cerr << v << ", ";
        } cerr << endl;
        //k個のランキングを更新するとき
        if(st.size()<=3){
            k_st.insert(y);
            ans += y;
        }
        if(k_st.size()>=3 and idx > (st.size()-k)){
            k_st.insert(y);
            ans += y;
            decltype(st)::iterator it = std::prev(st.end(), k+1); 
            ll popMinNum = *it;
            k_st.erase(popMinNum);
            ans -= popMinNum;
            cerr << "delete target it: " << *it << endl;
        }
    
        if(mp[x-1]){
            st.erase(mp[x-1]);
        }
        mp[x-1] = y;
    
        cerr << "ans: " << ans << endl;

    }

    return 0;
}