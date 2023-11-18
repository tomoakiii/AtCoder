#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <numeric> // std::iota()
#include <utility> // std::swap()

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
    int N, Q;
    cin >> N >> Q;
    WeightedUnionFind<long long> uf(N+1);
    int a, b;
    long long d;
    vector <int> ans;
    for (int i=1; i<=Q; i++){
        cin >> a >> b >> d;
        if (uf.unite(a, b, d)){
            ans.push_back(i);
        }
    }
    for (int i:ans){
        cout << i << " ";
    }
    return 0;
}