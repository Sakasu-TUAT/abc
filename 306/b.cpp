#include <bits/stdc++.h>
using namespace std;

int main(){
    long long ans = 0;
    long long ni = 1;
    bool flag = false;
    for(int i=0; i<=63; i++){
        int a; cin >> a;
        if(a==1 and i==0) flag = true;
        if(i!=0 and a==1){
            ans += ni;
            cerr << "ans: " << ans << endl;
        }
        if(i!=0) ni*=2;
    } 
    if(flag){
        cout << 2*ans+1 << endl;
    } else {
        cout << 2*ans << endl;
    }

    return 0;
}