#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    long long av = 0;
    for (int i=0; i<N; i++){
        cin >> A[i];
        av += A[i];
    }

    long long lw=av/N, up=lw, out = 0, out1 = 0;
    if (av%N != 0){
        up++;
    }
    for (int i=0; i<N; i++){
        out += max((long long)0, lw - A[i]);
        out1 += max((long long)0, A[i] - up);
    }
    cout << max(out, out1) << endl;
    return 0;
}