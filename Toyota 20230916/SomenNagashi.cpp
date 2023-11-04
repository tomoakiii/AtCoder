#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;
    struct person{
        long long leave_end;
        long long amount;
    };
    vector<person> row(N + 1);
    for (int n = 1; n <= N; n++){
        row[n].leave_end = 0;
        row[n].amount = 0;
    }
    long long lasttime = 0;
    for (int i = 1; i <= M; i++){
        long long T, W, S;
        cin >> T >> W >> S;
        bool isflowing = true;
        for (int j = 1; j <= N; j ++){
            if (isflowing && row[j].leave_end <= T)
            {
                row[j].amount += W;
                row[j].leave_end = T + S;
                isflowing = false;
                break;
            }
        }
    }

    for (int j = 1; j <= N; j ++){
        cout << row[j].amount << endl;
    }
	return 0;
}