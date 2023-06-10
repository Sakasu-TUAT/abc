#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int k = n/5;
    if((k+1)*5-n < n-(k*5)){
        cout << (k+1)*5;
    } else {
        cout << k*5;
    }
    return 0;
}