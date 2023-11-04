#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long


/* node number and time */
/* 最短経路問題 */

struct descend{
    bool operator()(pair<int, ll> const& a, pair<int, ll> const& b) {
        return a.second > b.second;
    }
};

/* Dijkstra's algorithm */
int main()
{
    long D[1001][1001];
    ll from1[1001], toN[1001];
    int N;
    ll A, B, C;

    priority_queue<pair<int, ll>, vector<pair<int, ll>>, descend> que;

    cin >> N >> A >> B >> C;
    for (int n=1; n<=N; n++){
        from1[n] = INF;
        toN[n] = INF;
    }
    from1[1] = 0;
    toN[N] = 0;

    for (int n=1; n<=N; n++){
        for (int i = 1; i <= N; i++){
            cin >> D[n][i];
        }
    }

    que.push(make_pair(1, 0)); // node-1 to node-1, time=0
    while (!que.empty()){
        int from = que.top().first; // from node
        ll tmpdist = que.top().second; // from node
        que.pop();
        if (tmpdist > from1[from]){
            continue;
        }

        for (int to = 2; to <= N; to++){
            ll alt = from1[from] + A*D[from][to];
            if (from1[to] > alt){
                from1[to] = alt;
                que.push(make_pair(to, from1[to]));
            }
        }
    }

    que.push(make_pair(N, 0)); // node-N to node-N, time=0
    while (!que.empty()){
        int from = que.top().first; // from node
        ll tmpdist = que.top().second; // from node
        que.pop();
        if (tmpdist > toN[from]){
            continue;
        }

        for (int to = N - 1; to >= 1; to--){
            ll alt = toN[from] + B*D[from][to] + C;
            if (toN[to] > alt){
                toN[to] = alt;
                que.push(make_pair(to, toN[to]));
            }
        }
    }

    ll ans = INF;
    for (int n=1 ; n<=N; n++){
        ll tmp = from1[n] + toN[n];
        if (ans > tmp){
            ans = tmp;
        }
    }

    cout << ans << endl;

 	return 0;
}