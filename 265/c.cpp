#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
using namespace std;
// #define rep(i,n) for(ll i=0; i<(n); ++i)
#define Out(x) cout << x << endl
#define Yes "Yes"
#define No "No"
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
using ll = long long;
using P = pair<int, int>;
// const ll mod = 10e9+7;

struct Point{
    int x,y;
    Point(int x=0, int y=0) :x(x),y(y){};
};

int main(){
	int h,w; cin>>h>>w;
    vector<vector<char>> a(h,vector<char> (w));
    rep(i,0,h){
        rep(j,0,w){
            cin>>a[i][j];
        }
    }
    Point currentPos(0,0);
    while(1){
        static int cnt=0;
        int i = currentPos.x; 
        int j = currentPos.y;
        if(a[i][j]=='U' and currentPos.x!=0){
            currentPos.x--;
        }
        else if(a[i][j]=='D' and currentPos.x!=h-1){
            currentPos.x++;
        }
        else if(a[i][j]=='L' and currentPos.y!=0){
            currentPos.y--;
        }
        else if(a[i][j]=='R' and currentPos.y!=w-1){
            currentPos.y++;
        }
        else {
            cout << currentPos.x+1 << " " << currentPos.y+1 << endl;
            return 0;
        }
        if(cnt>1e8){
            cout << "-1" << endl;
            return 0;
        }
        cnt++;
}

}
