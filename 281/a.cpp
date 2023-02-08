#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
using namespace std;
// #define rep(i,n) for(ll i=0; i<(n); ++i)
#define Out(x) cout << x << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
using ll = long long;
using P = pair<string, string>;
// const ll mod = 10e9+7;


int main(){
    string s;
    cin>>s;
    bool ok = false;
    string str = s.substr(1, 6);
    cerr << str << endl;
    int num = 0;
    num=(str[0]-'0')*1e5+(str[1]-'0')*1e4+(str[2]-'0')*1e3+(str[3]-'0')*1e2+(str[4]-'0')*1e1+(str[5]-'0');
    cerr << num << endl;
    if(((s[0]>='A' and s[0]<='Z') and (s[7]>='A' and s[7]<='Z')) 
     and (s.length() == 8) 
     and (num>=100000 and num<=999999)){
        cout << "Yes" << endl;
    }  else {
        cout << "No" << endl;
    }


    return 0;
}