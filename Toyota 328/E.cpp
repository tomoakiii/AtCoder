#include <bits/stdc++.h>

using namespace std;
class UnionFind {
public:
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> siz;

    // Constructor
    UnionFind(int N) : par(N), siz(N, 1) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }
    
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    bool unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return false; //xとyの根が同じ(=同じ木にある)時はそのまま
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
    
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        return root(x) == root(y);
    }
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
    auto comp = [](edge &a, edge &b){return a.w > b.w;}; // > (<) is smallest (largest) first
    priority_queue<edge, vector<edge>, decltype(comp)> smalledge(comp);
    for (int i=0; i<M; i++){
        edge tmp;
        cin >> tmp.from >> tmp.to >> tmp.w;
        smalledge.push(tmp);       
    }

    long long ans = 0;

    UnionFind uf(N+1);
    while(!smalledge.empty()){
        edge tmp;
        tmp = smalledge.top();
        smalledge.pop();
        if (!uf.same(tmp.from, tmp.to)){
            uf.unite(tmp.from, tmp.to);
            ans += tmp.w;
            ans %= K;
        }
    }
    cout << ans << endl;
    return 0;
}