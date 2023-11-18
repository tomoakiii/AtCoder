#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<double> P(N+1, 0);
    for (int j = 1; j <= N; j++){
        cin >> P[j];
    }
    struct calc{
        double sigpow9Q = 0;
        double R = -10000000;
    };
    vector<vector<calc>> dp(N+1, vector<calc>(N+1));

    double pow9;
    double sigpow9;
    pow9 = 1;
    sigpow9 = 0;

    double sigpow9Qkk = 0;
    for (int k = 1; k <= N; k++){
        sigpow9 = sigpow9 + pow9;
        pow9 = 0.9 * pow9;
        sigpow9Qkk = 0.9 * sigpow9Qkk + P[k];
        dp[k][k].sigpow9Q = sigpow9Qkk;
        dp[k][k].R = sigpow9Qkk/sigpow9 - 1200/sqrt(k);
        
        for (int i = k + 1; i <= N; i++){
            double sigpow9Q = 0.9 * dp[k-1][i-1].sigpow9Q + P[i];
            double R = sigpow9Q / sigpow9 - 1200 / sqrt(k);
            if (R < dp[k][i-1].R){
                dp[k][i].R = dp[k][i-1].R;
                dp[k][i].sigpow9Q = dp[k][i-1].sigpow9Q;
            }
            else{
                dp[k][i].R = R;
                dp[k][i].sigpow9Q = sigpow9Q;
            }
        }
    }

    double maxout = -1000000;
    for (int i = 1; i <= N; i++){
        maxout = max(maxout, dp[i][N].R);
    }
    cout << std::setprecision(24) << maxout << endl;
    return 0;
}