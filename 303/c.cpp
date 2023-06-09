#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<b; i++)

int main(){
    int n, m, h, k;
    string s;
    cin >> n >> m >> h >> k >> s;
    set<pair<int, int>> recoveryPos;
    rep(i,0,m){    
        int x, y; cin >> x >> y;
        recoveryPos.insert({x, y});
    }  
    pair<int, int> pos(0,0);
    rep(i,0,s.length()){
        h--;
        if(h<0){
            cout << "No" << endl;
            return 0;
        }
        if(s[i] == 'R'){
            pos.first++;
        } else if(s[i]=='L'){
            pos.first--;
        } else if(s[i] == 'U'){
            pos.second++;
        } else if(s[i] == 'D'){
            pos.second--;
        }
        if(recoveryPos.count(pos) and h < k){
            recoveryPos.erase(pos);
            h = k;
        }
    }
    cout << "Yes" << endl;

    return 0;
}