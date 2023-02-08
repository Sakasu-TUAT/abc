#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
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

int main(){
    int n; cin>>n;
    vector<int> even(n), odd(n);
    int evenCnt=0, oddCnt=0;
    rep(i,0,n){
        int a; cin >> a;
        if(a%2==0) even[evenCnt++]=a;
        else odd[oddCnt++]=a;
    }
    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());
    if(evenCnt<2 && oddCnt<2){
        cout << -1 << endl; return 0;
    }
    int ans = max({odd[0]+odd[1], even[0]+even[1]});
    cout << ans << endl;
    return 0;
}