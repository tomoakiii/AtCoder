#include <bits/stdc++.h>
#include <atcoder/modint.hpp>
using namespace std;
using mint = atcoder::modint998244353;

int main(){
    long N;
    cin >> N;
    string S;
    cin >> S;

    long output;

    for (int i=0; i<N-1; i++){
        if (S[i] != '1' && S[i+1] != '1'){
            cout << "-1" << endl;
            return 0;
        }
    }
    mint ans = 0;
    for (int i = N-1; i >=0; i--){
        
    }
    cout << endl;
    return 0;
}