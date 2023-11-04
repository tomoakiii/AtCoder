#include <bits/stdc++.h>
#define INF (1<<15)
#define KKKKK 7777
using namespace std;

int main()
{
    long long N, K, P;
    cin >> N >> K >> P;
    vector<long long> C(N + 1);
    vector<vector<int>> A(N + 1);
    for (int i = 1; i <= N; ++i){
		cin >> C[i];
		A[i] = vector<int>(K + 1);
		for (int j = 1; j <= K; j++){
			cin >> A[i][j];
		}
	}
	long long dp[6][6][6][6][6];
	
	memset(dp, 127, sizeof(dp));
	dp[0][0][0][0][0]=0;
	int ind[5];
	for (int i = 0; i < K; i++){
		ind[i] = P;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int a1 = ind[0]; ~a1; a1--){
			for (int a2 = ind[1]; ~a2; a2--){
				for (int a3 = ind[2]; ~a3; a3--){
					for (int a4 = ind[3]; ~a4; a4--){
						for (int a5 = ind[4]; ~a5; a5--){
							int b1 = max(0, a1 - A[i][1]);
							int b2 = max(0, a2 - A[i][2]);
							int b3 = max(0, a3 - A[i][3]);
							int b4 = max(0, a4 - A[i][4]);
							int b5 = max(0, a5 - A[i][5]);
							dp[a1][a2][a3][a4][a5] = min(dp[b1][b2][b3][b4][b5] + C[i], dp[a1][a2][a3][a4][a5]);
						}
					}
				}
			}
		}
	}

	if (dp[ind[0]][ind[1]][ind[2]][ind[3]][ind[4]] >= 1e11){
		cout << -1 << endl;
	}else{
		cout << dp[ind[0]][ind[1]][ind[2]][ind[3]][ind[4]] << endl;
	}
	return 0;
}