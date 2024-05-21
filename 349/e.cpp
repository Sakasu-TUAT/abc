#include <iostream>
#include <vector>
#include <utility> // std::swap()
#include <algorithm> // std::sort()
#include <map>
using ll = long long;
using namespace std;
/// @brief Union-Find 木
/// @note 1.4 高速化 + 省メモリ化
/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/union-find
class UnionFind
{
public:

	UnionFind() = default;

	/// @brief Union-Find 木を構築します。
	/// @param n 要素数
	explicit UnionFind(size_t n)
		: m_parentsOrSize(n, -1) {}

	/// @brief 頂点 i の root のインデックスを返します。
	/// @param i 調べる頂点のインデックス
	/// @return 頂点 i の root のインデックス
	int find(int i)
	{
		if (m_parentsOrSize[i] < 0)
		{
			return i;
		}

		// 経路圧縮
		return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
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
			// union by size (小さいほうが子になる）
			if (-m_parentsOrSize[a] < -m_parentsOrSize[b])
			{
				std::swap(a, b);
			}

			m_parentsOrSize[a] += m_parentsOrSize[b];
			m_parentsOrSize[b] = a;
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
		return -m_parentsOrSize[find(i)];
	}

private:

	// m_parentsOrSize[i] は i の 親,
	// ただし root の場合は (-1 * そのグループに属する要素数)
	std::vector<int> m_parentsOrSize;
};

/// @brief 辺
struct Edge
{
	/// @brief 辺の一方の頂点
	int u;

	/// @brief 辺のもう一方の頂点
	int v;

	/// @brief 辺の重み
	long long cost;

	bool operator <(const Edge& other) const
	{
		return (cost < other.cost);
	}
};

/// @brief 最小全域木
/// @note 1.1 クラスカル法で最小全域木の辺の重みの総和を求める
/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/minimum-spanning-tree
int main()
{
	// 頂点数 V, 辺数 E
    long long k; 
	int V, E;
	std::cin >> V >> E >> k;
    

	// 辺
	std::vector<Edge> edges(E);

    std::map<ll, ll> mp;
 
	for (auto& edge : edges)
	{
		std::cin >> edge.u >> edge.v >> edge.cost;
		--edge.u; --edge.v;
        if(mp[edge.cost]) {
            cout << "duplicate const : " << edge.cost << endl;
        }
        mp[edge.cost]++;

	}

	// 辺をコストの小さい順にソート
	std::sort(edges.begin(), edges.end());

	// Union-Find 木
	UnionFind uf(V);

	// 最小全域木の辺の重みの総和
	long long sum = 0;

	// コストが小さい順に並んだ各辺について
	for (const auto& edge : edges)
	{
		// この辺を加えても閉路にならない場合
		if (!uf.connected(edge.u, edge.v))
		{
			// グループに加える
			uf.merge(edge.u, edge.v);

			// 辺のコストを加算
            auto c = edge.cost%k;
			sum += (c+k)%k;
            sum%=k;
		}
	}

	std::cout << sum%k << '\n';
}