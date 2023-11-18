#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A, A0;
    cin >> N >> A0;
    bool isf = true;
    for (int i = 1; i < N; i++){
        cin >> A;
        if (A != A0){
            isf = false;
        }
    }
    if (isf){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}