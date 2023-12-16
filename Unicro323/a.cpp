#include <bits/stdc++.h>
using namespace std;

int main(){
    char S[16];     
    cin >> S;
    for (int i = 1; i < 16; i+=2){
        if (S[i]!='0'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}