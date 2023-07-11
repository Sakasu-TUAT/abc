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
    ll n, k;
    cin >> n >> k;
    ll cnt = 1;
    vector<pair<ll, ll>> p(n);
    ll sum = 0;
    map<ll, ll> mp;
    rep(i,0,n){
        int a, b;
        // cin >> a >> b;
        cin >> p[i].first >> p[i].second;
        sum += p[i].second;
        // mp[a]+=b;
    }
    sort(p.begin(), p.end());

    if(sum <= k) {
        cout << 1 << endl;
        return 0;
    }
    for(const auto &[day , num] : p){
        // cerr << "sum :" << sum << ", day: " << day << ", lastDrug: " << num << endl;
        sum -= num;
        if(sum<=k) {
            // cerr << "ans :" << endl;
            cout << day+1 << endl;
            return 0;
        } 
    }

    return 0;
}