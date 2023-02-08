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
    double a,b; cin>>a>>b;
    double c = b/a;
    vector<int> d;
    // if(b==0){
    //     cout << 0 << endl;
    //     return 0;
    // }
    c = c*10000;
    cerr << c << endl;
    // rep(i,0,4){
    //     // int d = c/pow(10,3-i);
    //     // cerr << "d: " << d << endl; 
    //     if()c = round(c);
    //     c /=10; 
    //     cerr << c << endl;
    // }
    c = round(c);
    c = c/10000;
    printf("%.3f\n", c);
    // std::cout << std::setprecision(3) << c << endl;
    // cerr << c << endl;

    return 0;
}