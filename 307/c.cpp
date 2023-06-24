#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}

const ll INF = 1e9;
const ll mod = 1000000007;


template<typename T>
bool isEqualSet(const set<T>& set1, const set<T>& set2) {
    if (set1.size() != set2.size())
        return false;
    for (const auto& element : set1) {
        if (set2.find(element) == set2.end())
            return false;
    }

    return true;
}

template<typename T>
void printSet(const set<T> st){
    cerr << "table : (" ;
    for(const auto &[x, y] : st) {
        cerr << x << ", " << y << ") (";
    }
    cerr << endl;
}

int main(){
    using tb = set<pair<int, int>>;
    vector<tb> pos(3);
    vector<pair<int, int>> tanten(3);
    int h, w;
    rep(i,0,3){
        cin >> h >> w;
        int maxH = -1, maxW = -1;
        rep(j,0,h){
            string s; cin >> s;
            rep(k,0,w){
                if(s[k]=='#'){
                    pos[i].insert({j, k});
                    chmax(maxH, j);
                    chmax(maxW, k);
                }
            }
        }
        tanten[i] = {maxH, maxW};
        cerr << "tanten(H, W) = " << maxH << ", " << maxW << endl;
    }

    for(const auto table : pos){
        printSet(table);
    }
    tb demo  = {{2,0}, {2,1}, {2,2}};
    for(int i = -10; i < h; i++){
    for(int j=-10; j < w; j++){
        tb modified_tb_1;
        for(auto p : pos[0]){
            modified_tb_1.insert({p.first+i, p.second+j});
        }
        for(int k = -10; k < 10; k++){
        for(int l = -10; l < 10; l++){    
            tb modified_tb_2;
            for(auto p : pos[1]){
                modified_tb_2.insert({p.first+k, p.second+l});
            }
            tb union_tb;
            union_tb.insert(modified_tb_1.begin(), modified_tb_1.end());
            union_tb.insert(modified_tb_2.begin(), modified_tb_2.end());
 
            if (isEqualSet(union_tb, pos[2])){
                printSet(union_tb);
                cout << "Yes" << endl;
                return 0;
            } 
        }}
    }}


    cout << "No" << endl;

    return 0;
}