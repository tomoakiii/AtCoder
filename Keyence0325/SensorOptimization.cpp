#include <bits/stdc++.h>
using namespace std;
#define INF LONG_MAX
/* dp */

int main()
{
    int N;
    long L1, L2, C1, C2;
    int K1, K2;
    cin >> N;
    vector<long> D(N, 0);
    for (int i = 0; i < N; i++){
        cin >> D[i];
    }
    cin >> L1 >> C1 >> K1;
    cin >> L2 >> C2 >> K2;
    vector<vector<long>> dp(N, vector<long>(K1+1, INF/2));
    long remD = D[0];
    for (int j = 0; j <= K1; j++){
        if (remD <= 0){
            // if negative remD firstly, this is completion to watch all D0 by Sensor1
            dp[0][j] = 0;
            break;            
        }
        dp[0][j] = (remD + L2 - 1)/L2;      
        remD -= L1;
    }

    for (int n = 1; n < N; n++){ // checking D[n]
        for (int j = 0; j <= K1; j++){ // checking D[n] : j x Sensor1, how many Sensor2?
            long remD = D[n];
            for(int k = j; k >= 0; k--){
                if (remD <= 0){
                    dp[n][j] = min(dp[n][j], dp[n-1][k]);
                    break;
                }
                dp[n][j] = min(dp[n][j], dp[n-1][k] + (remD+L2-1)/L2);
                remD -= L1;
            }  
        }
    }
    long ans = INF;
    for (int j = 0; j <= K1; j++){
        if (dp[N-1][j] > K2){
            continue;
        }
        ans = min(ans, dp[N-1][j] * C2 + j * C1);
    }
    if (ans == INF){
        cout << -1 << endl;        
    }else{
        cout << ans << endl;
    }
    return 0;
}