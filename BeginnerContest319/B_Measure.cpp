#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    string s;
    for (int i = 0; i <= N; i++){
        bool flg = false;
        for (int j = 1; j <= 9; j++){
            if ((i*j)%N == 0){
                cout << j;
                flg = true;
                break;
            }
        }
        if (!flg){
            cout << "-";
        }
    }
    
    cout << endl;
    return 0;
}