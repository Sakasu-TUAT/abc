#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> v;
    for(int i=0; i<n;i++){
        string s; cin >> s;
        v.emplace_back(s);
    }
    sort(v.begin(), v.end());
 
    do{
     bool ok = true;
        for(int i=0; i<n-1;i++){
            int cnt = 0;
            for(int j=0; j<m; j++){
                if(v[i][j]!=v[i+1][j])  cnt++;
            }   
            if(cnt != 1) ok = false;
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(v.begin(),v.end()));

    cout << "No" << endl;

    return 0;
}