#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, d;
    cin >> n >> m >> d;
    vector<long long> a(n), b(n);
    for(long long i=0; i<n; i++) cin >> a[i];
    for(long long i=0; i<m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(true){
        if((n==0) or (m==0)){
            cout << -1 << endl;
            return 0;
        }
        long long currentMaxA = a.back();
        long long currentMaxB = b.back();
        if(abs(currentMaxA-currentMaxB) <= d){
            cout << currentMaxA + currentMaxB << endl;
            return 0;
        } else {
            currentMaxA > currentMaxB ? a.pop_back() : b.pop_back();
        } 
        n = a.size();
        m = b.size();
    }

    return 0;
}