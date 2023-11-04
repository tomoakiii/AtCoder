#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<setprecision(20);
    long long N, M;
    cin >> N >> M;
    struct relpos
    {
        int to;
        long long x, y;
    };
    struct xy
    {
        long long x, y;
    };
    vector<relpos> graph[N + 1];
    for (long long n = 0; n < M; n++){
        relpos r;
        int from, to;
        cin >> from >> to >> r.x >> r.y;
        r.to = to;
        graph[from].push_back(r);
        r.to = from;
        r.x *= -1;
        r.y *= -1;
        graph[to].push_back(r);
    }

    vector<bool> posfix(N + 1, 0); // 0:Uundefined, 1:Fixed, 2:In-Que
    xy pos[N + 1];
    pos[1].x = pos[1].y = 0; 
    posfix[1] = 1;
    vector<int> que;
    que.push_back(1);
    while (que.size() >= 1){
        long long tmpfrom = que.back();
        que.pop_back();
        for (int j=0; j < graph[tmpfrom].size(); j++)
        {
            long long tmpto = graph[tmpfrom][j].to;
            if (posfix[tmpto]){
                continue;
            }else{
                pos[tmpto].x = pos[tmpfrom].x + graph[tmpfrom][j].x;
                pos[tmpto].y = pos[tmpfrom].y + graph[tmpfrom][j].y;
                posfix[tmpto] = true;
                que.push_back(tmpto);
            }
        }
    }
    for (int n = 1; n <= N; n++){
        if (!posfix[n])
        {
            cout << "undecidable" << endl; 
        } else {
            cout << pos[n].x << " " << pos[n].y << endl;
        }
    }
    return 0;
}