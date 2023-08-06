#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>
#include <numeric> // std::iota()

#define rep(i,a,b) for (ll i = (a); i < ll(b); i++)
#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<bool> Eratostenes(int n){
    vector<bool> isprime(n+1, true);isprime[1] = false;
    rep(p,2,n+1){ if(!isprime[p]) continue; for(int q = p*2; q <= n; q+=p){ isprime[q] = false; }}
    return isprime;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}
const ll INF = 1LL << 60;
const ll mod = 1000000007;
int dx[4] = {1, 0, 0, -1}; 
int dy[4] = {0, 1, -1, 0}; 

ll power(ll a, ll b) {
    ll ans = 1;
    for(ll i=0; i<60; i++){
        if(b & (1LL<<i)) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
    }
    return ans;
}

ll combination(ll n, ll k){
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    ll s = 1, t = 1;
    rep(i,1,k+1){
        s = s*(n-i+1) % mod;
        t = t*i % mod; 
    }
    // フェルマーの小定理 a^(p-1) ≡ 1 (mod.p) (∵ gcd(a, p) = 1)
    // より、tの逆元は t^(p-2) ≡ t^(-1) (mod. p)
    return s * power(t, mod-2) % mod;
}

class UnionFind
{
public:

	UnionFind() = default;

	/// @brief Union-Find 木を構築します。
	/// @param n 要素数
	explicit UnionFind(size_t n)
		: m_parents(n)
		, m_sizes(n, 1)
	{
		std::iota(m_parents.begin(), m_parents.end(), 0);
	}

	/// @brief 頂点 i の root のインデックスを返します。
	/// @param i 調べる頂点のインデックス
	/// @return 頂点 i の root のインデックス
	int find(int i)
	{
		if (m_parents[i] == i)
		{
			return i;
		}

		// 経路圧縮
		return (m_parents[i] = find(m_parents[i]));
	}

	/// @brief a のグループと b のグループを統合します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a != b)
		{
			m_sizes[a] += m_sizes[b];
			m_parents[b] = a;
		}
	}

	/// @brief a と b が同じグループに属すかを返します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @return a と b が同じグループに属す場合 true, それ以外の場合は false
	bool connected(int a, int b)
	{
		return (find(a) == find(b));
	}

	/// @brief i が属するグループの要素数を返します。
	/// @param i インデックス
	/// @return i が属するグループの要素数
	int size(int i)
	{
		return m_sizes[find(i)];
	}

private:

	// m_parents[i] は i の 親,
	// root の場合は自身が親
	std::vector<int> m_parents;

	// グループの要素数 (root 用)
	// i が root のときのみ, m_sizes[i] はそのグループに属する要素数を表す
	std::vector<int> m_sizes;
};

int main(){
    int n, m; cin >> n >> m;
    UnionFind uf(n);
    set<int> setA, setB;
    map<int, set<int>> mp;
    rep(i,0,m){
        int a, b; cin >> a >> b;
        setA.insert(a);
        setB.insert(b);
        mp[a].insert(b);
    }
    ll ans = -1;
    bool flag = true;
    int cnt = 0;
    for(const auto [strong, st] : mp){
        if(!setB.count(strong)) {
            cnt++;
            ans = strong;
        }
    }
    if(cnt == 1){
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }




    return 0;
}