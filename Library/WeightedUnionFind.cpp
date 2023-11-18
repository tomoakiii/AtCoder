#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <numeric> // std::iota()
#include <utility> // std::swap()

/// @brief 重み付き Union-Find 木
/// @tparam Type 重みの表現に使う型
/// @note 1.1 シンプルな実装
/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/weighted-union-find
template <class Type>
class WeightedUnionFind
{
public:

	WeightedUnionFind() = default;

	explicit WeightedUnionFind(size_t n)
		: m_parents(n)
		, m_sizes(n, 1)
		, m_diffWeights(n)
	{
		std::iota(m_parents.begin(), m_parents.end(), 0);
	}

	int find(int i)
	{
		if (m_parents[i] == i)
		{
			return i;
		}

		const int root = find(m_parents[i]);

		m_diffWeights[i] += m_diffWeights[m_parents[i]];

		// 経路圧縮
		return (m_parents[i] = root);
	}

	bool unite(int a, int b, Type w)
	{
		w += weight(a);
		w -= weight(b);

		a = find(a);
		b = find(b);

		if (a != b)
		{
			// union by size (小さいほうが子になる）
			if (m_sizes[a] < m_sizes[b])
			{
				std::swap(a, b);
				w = -w;
			}

			m_sizes[a] += m_sizes[b];
			m_parents[b] = a;
			m_diffWeights[b] = w;
            return true;
		} else {
            return (diff(a, b) == w);
        }
	}

	Type diff(int a, int b)
	{
		return (weight(b) - weight(a));
	}

	bool same(int a, int b)
	{
		return (find(a) == find(b));
	}

	int size(int i)
	{
		return m_sizes[find(i)];
	}
	
	vector <int> par(){
		return m_parents;
	}
private:
	std::vector<int> m_parents;
	std::vector<int> m_sizes;
	std::vector<Type> m_diffWeights;
	Type weight(int i)
	{
		find(i); // 経路圧縮
		return m_diffWeights[i];
	}
};


int main(){
    WeightedUnionFind<int> uf(9);
    int test[7][2] = {
        {4, 6},
        {4, 7},
        {4, 8},
        {5, 7},
        {5, 8},
        {6, 8},
        {7, 8}
    };

    for (auto t : test){
        bool chk = uf.unite(t[0], t[1], 2);
        cout << "<" << t[0] << ", " << t[1] << "> ";
        for (auto i: uf.par()) cout << i << " ";
        cout << "res " << chk << endl;
    }
}