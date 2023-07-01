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

bool compare(const pair<long double, ll>& a, const pair<long double, ll>& b) {
    return a.first < b.first; 
}


int main(){
    ll n; cin >> n;
    vector<pair<long double,ll>> p(n);
    map<long double, set<ll>> mp;
    rep(i,0,n){
        int a, b; cin >> a >> b;
        long double epsilon = std::numeric_limits<long double>::epsilon();
        p[i].first = (1+(long double)(b)/(long double)(a));
        p[i].second = i+1;
    }
    // sort(p.begin(), p.end());
    stable_sort(p.begin(), p.end(), compare);
    for(const auto &[score, idx] : p){
        mp[score].insert(idx);
    }
    // cout << endl;
    map<long double, bool> used;
    
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        const auto [score, st] = *it;
        if(used[score]) continue;
        used[score] = true;

        bool isLastElement = (std::next(it) == mp.end());
        if(!isLastElement){
            for(const auto idx : st){
                // cerr << "score: " << score << ", idx: " << idx << endl;    
                // cerr << "idx: " << idx << endl;
                cout << idx << " ";
            }
        } else {
            int cnt = 0;
            for(const auto idx : st){
                // cerr << "score: " << score << ", idx: " << idx << endl;    
                // cerr << "idx: " << idx << endl;
                cnt++;
                if(cnt==st.size()){
                    cout << idx;
                } else {
                    cout << idx << " ";
                }
               
            }
        }
   
       
        // if(used[idx]) continue;
        // used[idx] = true;
        // while(!mp[score].empty()){
        //     auto idx = mp[score].pop
            
        // }
    }
    cout << endl;
 

    return 0;
}