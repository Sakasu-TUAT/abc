#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cassert>

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
// const ll mod = 1000000007;


int main(){
    ll n; cin >> n;
    stack<char> st, tmp;
    int cnt = 0;
    rep(i,0,n){
        char c; cin >> c;
        st.push(c);
        if(c=='(') cnt++;
        if(c==')' and cnt>0){
            tmp = st;
            bool flag = false;
            while(!tmp.empty()){
                if(tmp.top() == '(') {
                    tmp.pop();
                    flag = true;
                    cnt--;
                    break;
                }
                tmp.pop();
            }
            if(flag) st = tmp;
        }
    }
    vector<char> ans;
    while(!st.empty()){
        ans.emplace_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    for(const auto &v : ans){
        cout << v;
    }



    
    return 0;
}