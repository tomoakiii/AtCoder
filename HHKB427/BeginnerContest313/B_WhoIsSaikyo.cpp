#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<bool> chk(N, true);
    int A, B;
    for (int i=1; i<=M; i++){
        cin >> A >> B;
        chk[B] = false;
    }
    int out=0;
    for (int i=1; i<=N; i++){
        if (chk[i]){
            if (out!=0){
                out = -1;
                break;
            }
            out = i;
        }
    }
    cout << out << endl;
    return 0;
}