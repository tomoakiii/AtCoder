#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, tmp;
    cin >> N >> K;
    vector<bool> A(N+1);
    vector<bool> tmpK(K+2);
    bool accumK=false;
    for (int i=1; i<=K+1; i++){
        cout << "? ";
        for (int j=1; j<=K+1; j++){
            if (i!=j){
                cout << j << " ";
            }
        }
        cout << endl;
        cin >> tmp;
        tmpK[i] = tmp==1;
        accumK ^= tmp;
    }
    for (int i=1; i<=K+1; i++){
        A[i] = accumK ^ tmpK[i];
    }



    accumK ^= A[1];
    for (int i=K+2; i<=N; i++){    
        accumK ^= A[i-K];
        cout << "? ";
        for (int j=i-K+1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
        cin >> tmp;
        A[i] = (tmp==1) ^ accumK;
        accumK = tmp;
    }

    cout << "! ";
    for (int i = 1; i<=N; i++){
        cout << A[i] << " ";    
    }
    cout << endl;
    return 0;
}