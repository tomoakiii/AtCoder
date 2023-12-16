#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> AS(N+1, vector<int>(M, 0));
    vector<int> S(N);
    for (int i =0; i<M; i++){
        cin >> AS[0][i];
    }

    int smax = 0;
    for (int i =0; i<N; i++){
        string st;
        cin >> st;
        S[i] = i+1;
        for (int j=0;j<M;j++){
            if (st[j] == 'o'){
                S[i] += AS[0][j];
                AS[i+1][j] = 0;
            } else {
                AS[i+1][j] = AS[0][j];
            }
        }
        if (smax < S[i]) {
            smax = S[i];
        }
    }

    for (int i =0; i<N; i++){
        sort(AS[i+1].begin(), AS[i+1].end());
        int delta = smax - S[i];
        int ind=M-1, cnt=0;

        while (delta > 0){
            delta -= AS[i+1][ind--];
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}