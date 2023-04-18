#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;
using mint = modint998244353;


int main(){
	int q;
    cin >> q;
    deque<int> d(1, 1);   //1を一つ持つの意
    mint ans = 1;
    while(q--){
        int i; cin >> i;
        if(i==1){
            int x; cin >> x;
            d.push_back(x);
            ans = 10*ans + x;
        }
        if(i==2){
            ans -= mint(10).pow(d.size()-1)*d.front();
            d.pop_front();
        }
        if(i==3){
            cout << ans.val() << endl;
        }
    }
}