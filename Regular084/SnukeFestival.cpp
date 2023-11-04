#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    vector<vector<long long>> ABC(3, vector <long long>(N, 0));
    
    for (int n = 0; n < 3; n++){
        for (int i = 0; i < N; i++){
            cin >> ABC[n][i];
        }
        sort(ABC[n].begin(), ABC[n].end());
    }
    
    vector<vector<long long>> AccumABC(3, vector <long long>(N+1, 1));
    for (int n = 1; n >= 0; n--)
    {
        AccumABC[n][N] = 0;
        long long accum = 0;
        long long lastind = N-1;
        bool isfin = false;
        for (int j = N - 1; j >= 0; j--)
        {
            if (isfin)
            {
                AccumABC[n][j] = accum;
                continue;
            }
            int k;
            for (k = lastind; k >= 0; k--)
            {
                lastind = k;
                if (ABC[n][j] >= ABC[n+1][k]){ // B is greater than C
                    break;
                }
                accum += AccumABC[n+1][k];
            }
            AccumABC[n][j] = accum; 
            if (k < 0){
                isfin = true;
            }
        }
    }

    long long ans = 0;
    for (int n = N-1; n >= 0; n--){
        ans+= AccumABC[0][n];
    }
    cout << ans << endl;

	return 0;
}