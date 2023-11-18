#include <bits/stdc++.h>
using namespace std;

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
    return 0;
}