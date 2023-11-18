#include <bits/stdc++.h>

using namespace std;

#include <iostream>

class combination{
public:
    long long N, R;
    vector<vector<long long>> comb = {};
    combination(long long n, long long r) : N(n), R(r){
        vector<bool> b(n, false);
        fill(b.end() - r, b.end(), true);
        do {
            vector<long long> c = {};
            for (long long i=0; i<n; i++) if (b[i]) c.push_back(i+1);
            comb.push_back(c);
        } while (std::next_permutation(b.begin(), b.end()));

    }
};

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
	bool unite(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a != b)
		{
			// union by size (小さいほうが子になる）
			if (m_sizes[a] < m_sizes[b])
			{
				std::swap(a, b);
			}

			m_sizes[a] += m_sizes[b];
			m_parents[b] = a;
            return true;
		} else {
            return false;
        }
	}

	/// @brief a と b が同じグループに属すかを返します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @return a と b が同じグループに属す場合 true, それ以外の場合は false
	bool same(int a, int b)
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
	// m_parents[i] は i の 親, root の場合は自身が親
	std::vector<int> m_parents;

	// グループの要素数 (root 用), i が root のときのみ, m_sizes[i] はそのグループに属する要素数を表す
	std::vector<int> m_sizes;
};

struct edge{
    int from;
    int to;
    long long w;
};

int main (){
    int N, M;
    long long K;
    cin >> N >> M >> K;
    vector<edge> edges(M+1);
    for (int i=1; i<=M; i++){
        edge tmp;
        cin >> edges[i].from >> edges[i].to >> edges[i].w;

    }

    long long ans = 0;
    combination comb(M, N-1);
    //reverse(comb.comb.begin(), comb.comb.end());
    long long mans=K+1;
    for (auto tcomb : comb.comb){
        UnionFind uf(N+1);
        long long ans = 0;
        for (int j : tcomb){
            if (!uf.unite(edges[j].from, edges[j].to)){
                ans = K+1;
                break;
            }
            ans += edges[j].w;
            ans %= K;
        }
        if (ans < mans){
            mans = ans;
        }
    }
    cout << mans << endl;
    return 0;
}