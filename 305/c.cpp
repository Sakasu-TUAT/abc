#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<b; i++)

int main(){
    int h, w; cin >> h >> w;
    vector<string> table;
    rep(i, 0, h){
        string s; cin >> s;
        table.push_back(s);
    }
    int colLength = -1;
    rep(i,0,h){
        int cnt = 0;
        rep(j,0,w){
            if(table[i][j] == '#'){
                cnt++;
            }
        }
        colLength = max(colLength, cnt);
    }
    int rowLength = -1;
    rep(i,0,w){
        int cnt = 0;
        rep(j,0,h){
            if(table[j][i] == '#'){

                cnt++;
            }
        }
        rowLength = max(rowLength, cnt);
    }
    cerr << "(H, W)=" << "(" << rowLength << ", " << colLength << ")" << endl;  
    // rep(i,0,h){
    //     bool isCookie = false;
    //     int cnt =0;
    //     int firstX = 0;
    //     rep(j,0,w){
    //         if(table[i][j] == '#' and isCookie == false){
    //             firstX = j;
    //             cnt++;
    //             isCookie = true;
    //             cerr << "started i, j = " << i << ", " << j << endl;
    //         } else if(table[i][j] != '#' and isCookie == true){
    //             cerr << "aida" << endl;
    //             cout << i+1 << " " << j+1 << " ";
    //             return 0;
    //         } else if(table[i][j] == '#' and isCookie == true){
    //             cnt++;
    //         }
    //     }
    //     if(cnt != colLength and cnt!=0){
    //         cerr << cnt << ", " << colLength << endl;
    //         cout << i+1 << " " << firstX << " ";
    //         return 0;
    //     }
    //     cnt = 0;
    // }
    pair<int, int> startPos = make_pair(-1, -1);
    pair<int, int> endPos = make_pair(-1, -1);
    int firstX = 1000000;
    int firstY;
    int tmpFirstX = 1000000;
    int cnt = 0;
    rep(i,0,h){
        bool isCookie = false;
        rep(j,0,w){
            if(table[i][j] == '#' and isCookie == false){
                tmpFirstX = j;
                if(cnt==0){
                    firstY = i;
                    cnt++;
                }
                isCookie = true;
            }
        }
        firstX = min(firstX, tmpFirstX);
    }
    cerr << "firstX, firstY = " << firstX << ", " << firstY << endl;
    rep(i,firstY,firstY+rowLength){
        rep(j,firstX,firstX+colLength){
            if(table[i][j] == '.'){
                cout << i+1 << " " << j+1 <<endl;
                return 0;
            }
        }
    }

    return 0;
}