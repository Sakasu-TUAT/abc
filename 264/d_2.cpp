#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <limits>
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
using P = pair<long, char>;
const ll INF = 1ll << 60;
// const ll mod = 10e9+7;

int main(){
    string s; cin>>s;
    map<string, int> mp;
    queue<string> q;
    mp[s] = 0;
    q.push(s);

    while(!q.empty()){
        string current = q.front(); q.pop();
        if(current == "atcoder"){
            cout << mp[current] << endl;
            return 0;
        }
        rep(i,1,7){
            string next = current;
            swap(next[i-1], next[i]);
            //隣入れ替えたやつが記録済みでなかったら新たにpushし、次のcurrentに
            if(mp.find(next)==mp.end()){
                q.push(next);
                mp[next] = mp[current] + 1;
            }
        }
    }

    return 0;
}