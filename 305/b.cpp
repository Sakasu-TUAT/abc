#include <bits/stdc++.h>
using namespace std;

int main(){
    char p, q; cin >> p >> q;
    map<char, int> mp = {
        {'A', 0}, {'B', 3}, 
        {'C', 4}, {'D', 8},
        {'E', 9}, {'F', 14},
        {'G', 23}
    };
    cout << abs(mp[p] - mp[q]) << endl;
    return 0;
}