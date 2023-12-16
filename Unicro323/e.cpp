#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;

long long pow(long long a, long long n){
    long long ret=1;
    for(; n>0; n>>=1, a=a*a % MOD ){
        if(n % 2 == 1){
            ret = ret * a % MOD;
        }
    }
    return ret;
}

long long modinv(long long a){
    return pow(a, MOD - 2);
}


int main(){
    long long N, X;
    cin >> N >> X;
    vector<long long> T(N);
    for(auto &t: T){
        cin >> t;
    }

    long long invN = modinv(N);

    vector<vector<long long>> dp0(N);
    for (int i = 0; i < N; i++){
        dp0[i] = vector<long long>(T[i], 0);
    }
    vector<vector<vector<long long>>> dp(X+1, dp0);
    long long newplay = 0, newplay_old = 0;
    for (int i = 0; i < N; i++){
        dp[0][i][0] = invN;
        newplay = (newplay + dp[0][i][T[i]-1]) % MOD;
    }
    newplay_old = newplay;
    // sec=1 --> sec=2 is 100%
    for(int t=1; t<X+1; t++) {
        newplay = 0;
        long long tmpnew = (newplay_old * invN) % MOD;
        for (int i = 0; i < N; i++){
            dp[t][i][0] = tmpnew;
            for (int j=1; j<T[i]; j++){
                dp[t][i][j] = dp[t-1][i][j-1];
            }
            newplay = (newplay + dp[t][i][T[i]-1]) % MOD;
        }
        newplay_old = newplay;
    }

    long long lout = 0;
    for (int j=0; j<T[0]; j++){
        lout = (lout + dp[X][0][j]) % MOD;
    }
    cout << lout << endl;

    return 0;
}

