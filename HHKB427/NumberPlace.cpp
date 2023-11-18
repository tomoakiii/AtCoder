#include <bits/stdc++.h>
//#include<iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N+1);
    vector<vector<int>> A(2, vector<int>(M+1));

    for (int i = 0; i<2; i++){
        for (int j = 1; j<=M; j++){
            cin >> A[i][j];
        }
    }

    vector<int> X(N+1, 1);
    for (int j = 1; j<=M; j++){
        G[A[0][j]].push_back(A[1][j]);
        X[A[0][j]] = -1;
        G[A[1][j]].push_back(A[0][j]);
        X[A[1][j]] = -1;
    }
    queue<int> que;
    que.push(A[0][1]);
    X[A[0][1]] = 0;
    while (!que.empty()){
        int fr = que.front();
        que.pop();
        int rev = (X[fr] == 0)?1 : 0;
        for (int ind : G[fr]){
            if (X[ind] == X[fr]){
                cout << "No" << endl;
                return 0;
            }
            if (X[ind] == -1){
                que.push(ind);
                X[ind] = rev;
            }
        }
        if (que.empty()){
            for (int i = 1; i <= N; i++){
                if (X[i] == -1){
                    X[i] = 0;
                    que.push(i);
                    break;
                }
            }
        }
    }

    // for (int i = 1; i <= N ; i++){
    //     cout << X[i] << " ";
    // }
    cout << "Yes" << endl;
    return 0;
    
}