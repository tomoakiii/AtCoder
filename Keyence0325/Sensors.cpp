#include <bits/stdc++.h>
using namespace std;


char maps[1002][1002];
int H, W;

void bfs(int xxx, int yyy)
{
    maps[yyy][xxx] = '.';
    queue<pair<int, int>> q;
    q.push({xxx, yyy});
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int y = yy - 1; y <= yy + 1 ; y++)
        {
            for (int x = xx - 1; x <= xx + 1; x++){
                if (y < 0 || y >= H || x < 0 || x >= W){
                    continue;
                }
                if (maps[y][x] == '.'){
                    continue;
                }
                maps[y][x] = '.';
                q.push({x, y});
            }
        }
    }
}

int main () {
    cin >> H >> W;
    for (int n = 0; n < H ; n++)
    {
        cin >> maps[n];
    }
    
    long long count = 0;
    for (int y = 0; y < H ; y++)
    {
        for (int x = 0; x < W; x++){
            if (maps[y][x] == '#'){
                count++;
                bfs(x, y);
            }
        }
    }
    cout << count << endl;
    return 0;
}
