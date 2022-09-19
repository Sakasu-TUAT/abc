#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
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
void printVector(const vector<string>vec);
bool lenghCheck();
bool TCheck(const vector<string>t);

string ans="";
ll n,m;
int main(){
    cin >> n >> m;
    vector<string> s(n),t(n);
    rep(i,0,n) cin >> s[i];
    rep(i,0,n) cin >> t[i];
    bool result = true;
    // rep(i,0,n)cout << s[i] << endl;
    do {
        printVector(s);
        cerr << ans << endl;
        result =lenghCheck()&&TCheck(t);
        do {

        }while(next_permutation(s.begin(), s.end()));
        if(result == true){
            cerr << "OK: ";
            cout << ans << endl;
            return 0;
        } 
        ans = "";
    }while(next_permutation(s.begin(), s.end()));
    cout << "-1" << endl;
}



void printVector(const vector<string>vec) {
    int cnt =0;
    for (string value : vec) {
            ans = ans+ value +"_";
            cnt++;
    }
    ans.erase(ans.length()-1,1);
}
bool lenghCheck(){
    if(ans.length()>=3 and ans.length()<=16){
        cerr << "length OK: ";
        return true;
    } else {
        cerr << "lengthErr: ";
        return false;
    }
}
bool TCheck(const vector<string>t){
    rep(i,0,n){
        if(ans == t[i]){
             cerr << "TErr: ";
            return false;
        }
    }
    cerr << "T OK: ";
    return true;
}