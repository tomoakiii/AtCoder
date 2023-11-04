#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    long long W, X;
    vector <long long> cal(24, 0); 
    for (int n = 0; n < N; n++){
        cin >> W >> X;
        for (int time = 9; time <= 17; time++){
            cal[(time + X) % 24] += W;
        }
    }
    long long max = 0;
    for (int time = 0; time <= 23; time++){
        if (max < cal[time])
        {
            max = cal[time];
        }
    }
    cout << max << endl;
    return 0;
}
