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
    int n; cin>>n;
    int c=n;
    vector<int> a(10000);
    int cnt=0;
    char b[]={'A', 'B', 'C', 'D', 'E','F'};

    while(n!=0){
        a.emplace_back(n%16);
        n/=16;
        // cerr << n << endl;
        cnt++;
    }
    
    reverse(a.begin(), a.end());
    if(c==0){
        cout<<"00"; return 0;
    }
    if(cnt<=1){
        cout<<"0";
    }
    for(auto &v:a){
        if(v==0) return 0;
        if(v>10){
            cout<< b[(v-10)];
        }else if(v==10){
            cout << "F";
        }else{
            cout << v;
        }
    }
    return 0;
}