#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
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
using P = pair<vector<ll>, bool>;
// const ll mod = 10e9+7;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

unordered_map<ll, ll> memo;


// 素因数分解
// 460 = 2^2 x 5 x 23 の場合
// 返り値は {{2, 2}, {5, 1}, {23, 1}}
vector<pair<long long, long long> > prime_factorize(long long N) {
    // 答えを表す可変長配列
    vector<pair<long long, long long> > res;

    // √N まで試し割っていく
    for (long long p = 2; p * p <= N; ++p) {
        // N が p で割り切れないならばスキップ
        if (N % p != 0) {
            continue;
        }

        // N の素因数 p に対する指数を求める
        int e = 0;
        while (N % p == 0) {
            // 指数を 1 増やす
            ++e;

            // N を p で割る
            N /= p;
        }

        // 答えに追加
        res.emplace_back(p, e);
    }

    // 素数が最後に残ることがありうる
    if (N != 1) {
        res.emplace_back(N, 1);
    }
    return res;
}

ll facctorialMethod(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

int main(){
    ll k; cin>>k;
    const auto& pf = prime_factorize(k);

    ll ans = 0;
    map<ll, ll> mp;
    vector<ll> a(pf.size());
    int i=0;
    for (auto v : pf) {
        // cout << v.first << "^" << v.second << " "; 
        a[i] = (static_cast<ll>(pow(v.first, v.second)));
        ans = max(static_cast<ll>(pow(v.first, v.second)), ans);
        i++;
    }
    sort(a.begin(), a.end(), greater<ll>());
    for(const auto &s : a){
        cerr << s << endl;
    }

    for(ll i=0; i<a.size(); i++){
        ll tmp = (facctorialMethod(a[i]));
        bool ok = true;
        for(ll j=0; j<a.size(); j++){
            cerr << "tmp: " << tmp <<", a[i]: "<<a[i] << ", a[j]: "<<a[j]<<", tmp%a[j] = "<< tmp%a[j] << endl;
            if(tmp%a[j]!=0){
                cerr <<"out\n"; 
                ok *= false;
            } 
        }
        if(ok)ans = a[i];

    }
       

    cout <<  ans << endl;

    return 0;
}